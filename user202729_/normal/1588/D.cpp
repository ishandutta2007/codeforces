// time-limit: 2000
// problem-url: https://codeforces.com/contest/1588/problem/D
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>

void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

int const numChar=52;

auto const chars=[]{
	std::array<char, numChar> chars;
	int pos=0;
	for(int i='a'; i<='z'; ++i) chars[pos++]=(char)i;
	for(int i='A'; i<='Z'; ++i) chars[pos++]=(char)i;
	assert(pos==(int)chars.size()); return chars;
}();

auto const charIndexOf=[]{
	std::array<int, 128> charIndexOf;
	charIndexOf.fill(INT_MAX);
	for(int i=0; i<numChar; ++i) charIndexOf[chars[i]]=i;
	return charIndexOf;
}();

void up(){ // 5 
	int numString; std::cin>>numString;
	std::vector<std::string> strings(numString); for(auto& s: strings) std::cin>>s;

	std::vector<std::array<std::array<int, 2>, numChar>> pos(numString);
	// [string index][charIndex]= list of locations, or INT_MAX if not available
	for(int stringIndex=0; stringIndex<numString; ++stringIndex){

		for(int charIndex=0; charIndex<numChar; ++charIndex){
			pos[stringIndex][charIndex].fill(INT_MAX);
		}

		for(int index=0; index<(int)strings[stringIndex].size(); ++index){
			auto const curChar=strings[stringIndex][index];
			auto& curPos=pos[stringIndex][charIndexOf[curChar]];
			*std::find(begin(curPos), end(curPos), INT_MAX)=index;
		}
	}


	// ||  52
	// each string len  52  2=104
	
	std::vector<int> states;
	// 2^10  52
	
	

	auto const posMask=(1<<numString)-1;

	std::vector<int> availableCharIndices;
	for(int charIndex=0; charIndex<numChar; ++charIndex)
		if(std::all_of(begin(pos), end(pos), [&](auto const& it){return it[charIndex][0]!=INT_MAX;}))
			availableCharIndices.push_back(charIndex);

	for(auto charIndex: availableCharIndices)
		for(int mask=0; mask<(1<<numString); mask++){
			if([&]{
				for(int i=0; i<numString; ++i)
					if(pos[i][charIndex][mask>>i&1]==INT_MAX) return false;
				return true;
			}()){
				states.push_back(charIndex<<numString|mask);
			}
		}

	std::sort(begin(states), end(states), [&](auto const& first, auto const& sec){
		return 
			pos[0][first>>numString][first&1]
			<
			pos[0][sec>>numString][sec&1]
			;
	}); // 52K  log 52K


	std::pair<int, int> result {0, -1};
	std::vector<std::pair<int, int>> valueOf(
			numChar<<numString
			);
	for(auto const state: states){ // 52K 
		std::pair<int, int> value{0, -1};

		/*
		for(auto prev)
			value=std::max(value, value[prev]);
			*/
		// 52  10

		if((state&posMask)==posMask){
			// "000"  "111"
			value=std::max(value, std::pair{valueOf[state-posMask].first, state-posMask});
		}

		auto const curChar=state>>numString;
		for(auto prevChar: availableCharIndices) if(prevChar!=curChar){
			[&]{
				int prevState=prevChar<<numString;
				for(int stringIndex=0; stringIndex<numString; ++stringIndex){
					if(pos[stringIndex][prevChar][0]
							>=
							pos[stringIndex][curChar][state>>stringIndex&1]
					  )
						return;

					if(
							pos[stringIndex][prevChar][1]
							<
							pos[stringIndex][curChar][state>>stringIndex&1]
					  )
					prevState|=1<<stringIndex;
				}

				value=std::max(value, {valueOf[prevState].first, prevState});
			}();
		}

		++value.first;
		valueOf[state]=value;
		result=std::max(result, std::pair{value.first, state});
	}

	std::cout<<result.first<<'\n';
	std::string s;
	auto state=result.second;
	while(state!=-1){
		s=chars[state>>numString]+s;
		state=valueOf[state].second;
	}
	std::cout<<s<<'\n';

}