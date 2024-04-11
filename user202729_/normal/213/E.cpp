// Cleaned up code. See also previous submission for deleted comments.
// A little code is copied from my KMP existing code. (problem 1161B)
// I had to write a test generator too but it only takes (took?) 1-2 minutes.
#ifndef LOCAL
#define NDEBUG
#endif
#include<set>
#include<cassert>
#include<vector>
#include<algorithm>
#include<iostream>

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int asize,bsize;std::cin>>asize>>bsize;
	std::vector<int> a(asize),inva(asize),invb(bsize);
	for(int i=0;i<asize;++i){
		std::cin>>a[i];
		--a[i];
		inva[a[i]]=i;
	}

	for(int i=0;i<bsize;++i){
		int bi;std::cin>>bi;
		--bi;
		invb[bi]=i;
	}

	std::vector<int> mingt(asize,-1), // [i] = min value int inva[0..i-1] > inva[i], or -1
		maxlt(asize,-1);
	{
		std::set<int> vals;
		for(int i=1;i<asize;++i){
			vals.insert(inva[i-1]);
			auto iter=vals.lower_bound(inva[i]);
			if(iter!=end(vals)){
				assert(*iter>inva[i]);
				mingt[i]=*iter;
			}
			if(iter!=begin(vals)){
				--iter;
				maxlt[i]=*iter;
			}
		}
	}

	std::vector<int> shift(asize+1); // shift[i] = min (sh) such that a[sh:i] permutation-matches a[:i-sh].
	shift[0]=1;
	for(int i=1;i<(int)shift.size();++i){
		shift[i]=shift[i-1];
		while(shift[i]<i){
			auto const sh=shift[i];
			auto const b=i-1-sh;

			assert(maxlt[b]<0 or inva[a[maxlt[b]]]<inva[b]);
			assert(mingt[b]<0 or inva[a[mingt[b]]]>inva[b]);

			if(
					(maxlt[b]<0 or inva[a[maxlt[b]]+sh]<inva[i-1]) and
					(mingt[b]<0 or inva[a[mingt[b]]+sh]>inva[i-1]))
				// inva[:i-sh] matches inva[sh:i]
				break;
			else
				shift[i]+=shift[b];
		}
		assert(shift[i]<=i);
	}

	int out=0; // number of substrings of length (asize) of (invb) that permutation-matches (inva).

	int i=0,match=0;
	while(i<bsize){
		// going to advance i and update match correspondingly.
		if(match==asize)
			match-=shift[match];

		while(match>=0){
			assert(maxlt[match]<0 or inva[a[maxlt[match]]]<inva[match]);
			assert(mingt[match]<0 or inva[a[mingt[match]]]>inva[match]);

			auto const sh=i-match;
			if(
					(maxlt[match]<0 or invb[a[maxlt[match]]+sh]<invb[i]) and
					(mingt[match]<0 or invb[a[mingt[match]]+sh]>invb[i]))
				// inva[:match+1] matches invb[sh:i+1]
				break;
			else
				match-=shift[match];
		}
		if(match<0) assert(match==-1);
		++match;++i;

		if(match==asize){
			++out;
		}
	}

	std::cout<<out<<'\n';
}