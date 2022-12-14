#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<array>
#include<string>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	std::array<int,2> cnt_s{};
	{
		std::string tmp;std::cin>>tmp;
		for(char c:tmp)
			++cnt_s[c-'0'];
	}

	std::string pat;
	std::cin>>pat;

	std::vector<int> shift(pat.size());
	shift[0]=1;
	for(int i=1;i<(int)shift.size();++i){
		shift[i]=shift[i-1];
		while(shift[i]<i and pat[i-1]!=pat[i-1-shift[i]])
			shift[i]+=shift[i-1-shift[i]];
		assert(shift[i]<=i);
	}

	int i=0,match=0;
	std::for_each(begin(pat)+1,end(pat),[&](char c){
		while(match>=0 and c!=pat[match])
			match-=shift[match];
		if(match<0) assert(match==-1);
		++match;++i;
	});

	// prefix & suffix of length (match) of pat is the same

	std::array<int,2> cnt_pat_pre_overlap{};
	std::for_each(begin(pat),end(pat)-match,[&](char c){
		++cnt_pat_pre_overlap[c-'0'];
	});

	std::array<int,2> cnt_pat_overlap{};
	std::for_each(end(pat)-match,end(pat),[&](char c){
		++cnt_pat_overlap[c-'0'];
	});

	// shortest string with n>0 occurence of t = (pat_pre_overlap*n + pat_overlap)

	int n=0;
	if(
			cnt_pat_pre_overlap[0]+cnt_pat_overlap[0]<=cnt_s[0] and
			cnt_pat_pre_overlap[1]+cnt_pat_overlap[1]<=cnt_s[1]){
		n=INT_MAX;
		for(int i=0;i<2;++i)
			if(cnt_pat_pre_overlap[i])
				n=std::min(n,(cnt_s[i]-cnt_pat_overlap[i])/cnt_pat_pre_overlap[i]);
		assert(n!=INT_MAX and n>0);

		std::string pre_overlap(begin(pat),end(pat)-match);

		for(int i=n;i--;)
			std::cout<<pre_overlap;

		std::cout
			<<std::string(end(pat)-match,end(pat))

			<<std::string(cnt_s[0]-cnt_pat_pre_overlap[0]*n-cnt_pat_overlap[0],'0')
			<<std::string(cnt_s[1]-cnt_pat_pre_overlap[1]*n-cnt_pat_overlap[1],'1')

			<<'\n';
	}else{
		std::cout
			<<std::string(cnt_s[0],'0')
			<<std::string(cnt_s[1],'1')

			<<'\n';
	}
}