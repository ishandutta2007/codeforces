// .........
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
	int n; std::cin>>n;
	std::array<std::pair<std::string, int>, 3> strings;

	int x=0;
	for(auto& [it, dominant]: strings){
		std::cin>>it;
		for(auto& ch: it){ ch-='0'; assert(0<=ch and ch<=1); }
		dominant=std::count(begin(it), end(it), 1)>=n;
		x+=dominant;
	}
	
	int dominant=x>=2;
	std::vector<std::string> good;
	for(auto& [it, curDominant]: strings){
		if(dominant==curDominant){
			good.push_back(std::move(it));
			if(good.size()==2) break;
		}
	}

	assert(good.size()==2);
	auto a=std::move(good[0]), b=std::move(good[1]);
	if(std::count(begin(a), end(a), dominant)<std::count(begin(b), end(b), dominant))
		std::swap(a, b);

	assert((int)a.size()==n*2);
	assert((int)b.size()==n*2);

	int pointer=0;
	std::string result; result.reserve(n*3);
	for(auto ch: a){
		auto const matchB=[&]{ return pointer<(int)b.size() and b[pointer]==ch; };

		if(not matchB() and ch==dominant){
			while(pointer<(int)b.size() and b[pointer]!=dominant){
				result+=b[pointer];
				++pointer;
			}
		}

		if(matchB()) ++pointer;
		result+=ch;
	}
	while(pointer<(int)b.size() and b[pointer]!=dominant){
		result+=b[pointer];
		++pointer;
	}

	auto const isSubsequence=[&](std::string const& a, std::string const& b){
		auto iterator=a.begin();
		for(auto it: b) if(*iterator==it){
			++iterator;
			if(iterator==a.end()) return true;
		}
		return false;
	};

	assert((int)result.size()<=n*3);
	assert(isSubsequence(a, result));
	assert(isSubsequence(b, result));

	for(auto& ch: result) ch+='0';
	std::cout<<result<<'\n';


}