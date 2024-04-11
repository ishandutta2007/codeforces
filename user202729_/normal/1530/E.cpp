// time-limit: 2000
// problem-url: https://codeforces.com/contest/1530/problem/E

//... didn't notice the wrong answer (?)
// can be expected, there are quite a lot of cases
//
// ... forgot this case.

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

void up(){
	std::string s; std::cin>>s;
	std::array<int, 26> count{};
	for(auto& ch: s) count[ch-'a']++;

	// can f(t)=0?
	auto it=std::find(begin(count), end(count), 1);
	if(it!=count.end()){
		// first character is i
		int const i=int(it-count.begin());
		std::cout<<char(i+'a');
		assert(count[i]==1);
		count[i]=0;

		for(int x=0; x<(int)count.size(); ++x)
			std::cout<< std::string(count[x], char(x+'a'));
		std::cout<<'\n';
		return;
	}


	int first=0;
	assert(s.size()>=1); // therefore there's a smallest character
	while(not count[first]) first++;

	if(count[first]==(int)s.size()){
		// s consist of only this character. There's only one different permutation. Must be correct
		std::cout<<s<<'\n';
		return;
	}
	// otherwise there's a second smallest character

	// greedy works. 2 first characters are (first, first)
	if(count[first]>=2 and
			(int)s.size()-count[first]
			>=
			(count[first]-1)-1
	  ){
		std::cout
			<< char(first+'a')
			<< char(first+'a');
		// there must not be "aa" in the suffix of s.size()-1 characters
		// there are enough characters to riffle them between the 'a' characters in that suffix
		int count_first=count[first]-=2;
		int p=first+1;
		while(true){

			// find next p with count[p]!=0, or if there's none, complete the string
			while(true){
				if(p==(int)count.size()){
					assert(count_first==0);
					std::cout<<'\n';
					return;
				}

				if(count[p]==0) p++;
				else break; // found p.
			}

			std::cout<<char(p+'a');
			--count[p];
			if(count_first){
				std::cout<<char(first+'a');
				--count_first;
			}
		}
	}

	// otherwise (the next option) 2 first characters are (first, second)
	// (second is guaranteed to exist, see above)
	int second=first+1;
	while(not count[second]) second++;

	// there are only those 2 characters?
	if(count[first]+count[second]==(int)s.size()){
		std::cout
			<< char(first+'a')
			<< std::string(count[second], char(second+'a'))
			<< std::string(count[first]-1, char(first+'a'))
			<<'\n';
		return;
	}

	// otherwise (greedy) 2 first characters are (first, second), and it's possible to make (first, second)
	// not appear in the rest
	std::cout
		<< char(first+'a')
		<< char(second+'a');

	--count[first];
	--count[second];

	// *now* count=count of remaining characters
	std::cout
		<< std::string(count[first], char(first+'a'));

	// *now* count=count of remaining characters except count[first] being the count of remaining characters before the print right above
	if(count[first] and count[second]){
		// if strictly greedy algorithm is used (first, second) would appear in the rest
		// have to insert a third character here
		// (third guaranteed to exist, check above)
		int third=second+1;
		while(not count[third]) third++;
		std::cout<<char(third+'a');
		--count[third];
	}

	count[first]=0;
	// *now* count=count of remaining characters
	
	for(int x=second; x<(int)count.size(); ++x)
		std::cout<< std::string(count[x], char(x+'a'));
	std::cout<<'\n';
	
}