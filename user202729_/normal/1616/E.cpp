// time-limit: 1000
// problem-url: https://codeforces.com/contest/1616/problem/E
#if not LOCAL
#define NDEBUG 1
#endif
#include<bits/stdc++.h>
// { ==== Begin library BITSum.h ====

template<class T>
struct Tree{
	std::vector<T> data;
	Tree(int number=0): data(number){}
	void reset(int number){data.clear(); data.resize(number);}

	template<bool strict=true>
	T sumSuffix(int index)const{
		if(strict){
			assert(0<=index); assert(index<=(int)data.size());
		}
		T result{};
		while(index<(int)data.size()){
			result+=data[index];
			index|=index+1;
		}
		return result;
	}
	T sum(int left, int right) const{
		assert(0<=left); assert(left<=right); assert(right<=(int)data.size());
		return sumSuffix(left)-sumSuffix(right);
	}

	template<bool strict=true>
	void add(int index, T delta){
		if(strict){
			assert(0<=index); assert(index<(int)data.size());
		}
		++index;
		while(index>0){
			data[index-1]+=delta;
			index&=index-1;
		}
	}
};

// } ==== End library BITSum.h ====
void up();
int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int numTest; std::cin>>numTest;
	while(numTest--) up();
}

void up(){
	int number; std::cin>>number;
	std::string s; std::cin>>s;
	std::string t; std::cin>>t;
	if(0){
		auto s1=s; std::sort(begin(s1), end(s1));
		if(s1>=t){std::cout<<"-1\n"; return;}
	}

	std::array<std::vector<int>, 127> pos;
	for(int index=number; index--;)pos[s[index]].push_back(index);

	Tree<int> remain(number);
	for(int index=0; index<number; ++index)
		remain.add(index, 1);

	int64_t result=INT64_MAX, curSwapped {};
	for(int index=0; index<number; ++index){
		int minStrictlyLessPos=INT_MAX;
		for(int p='a'; p<t[index]; ++p)
			if(not pos[p].empty())
				minStrictlyLessPos=std::min(minStrictlyLessPos,
						pos[p].back());
		if(minStrictlyLessPos<INT_MAX)
			result=std::min(result,
					curSwapped+remain.sum(0, minStrictlyLessPos)
					);

		if(pos[t[index]].empty()) break;
		curSwapped+=remain.sum(0, pos[t[index]].back());
		remain.add(pos[t[index]].back(), -1);
		pos[t[index]].pop_back();
	}
	std::cout<<(result==INT64_MAX ? -1: result)<<'\n';
	
}