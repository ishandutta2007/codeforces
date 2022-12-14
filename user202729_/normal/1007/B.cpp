#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<climits>
#include<array>
#include<vector>
#include<algorithm>

std::vector<std::vector<int>> fac=[]{ // list of factors
	std::vector<std::vector<int>> fac(100001);
	for(int d=1;d<(int)fac.size();++d)
		for(int i=d;i<(int)fac.size();i+=d)
			fac[i].push_back(d);
	return fac;
}();
int64_t binom(int64_t n,int k){
	int64_t out=1;
	for(int i=1;i<=k;++i)
		out=out*(n+1-i)/i;
	if(n==k)assert(out==1);
	return out;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);

	int ntest;std::cin>>ntest;
	while(ntest--){
		std::array<int,3> a;
		for(int& x:a)std::cin>>x;
		std::sort(begin(a),end(a));

		// should there be a better way to solve this?... (TODO read editorial)
		std::array<int,1<<3> cnt;
		cnt[0]=0; // not important
		for(int mask=1;mask<(1<<3);++mask){
			int gcd=0;
			for(int i=0;i<3;++i)if(mask>>i&1)
				gcd=std::__gcd(gcd,a[i]);
			cnt[mask]=(int)fac[gcd].size();
		}

		for(int bit=1<<3;bit>>=1;)
			for(int i=0;i<(1<<3);++i)
				if(i<(i|bit))
					cnt[i]-=cnt[i|bit];

		int64_t ans =0;
		for(int s1=1 ;s1<8;++s1)if(cnt[s1]) // otherwise ans won't change
		for(int s2=s1;s2<8;++s2)if(cnt[s2])
		for(int s3=s2;s3<8;++s3)if(cnt[s3]){
			if(
			((s1&4) and (s2&2) and (s3&1)) or 
			((s1&4) and (s2&1) and (s3&2)) or 
			((s1&2) and (s2&1) and (s3&4)) or 
			((s1&2) and (s2&4) and (s3&1)) or 
			((s1&1) and (s2&2) and (s3&4)) or 
			((s1&1) and (s2&4) and (s3&2))
			){ // valid 3-tuple (there's one with bit 0 set, one with bit 1 set, one with bit 2 set
				if(s1==s2 and s1==s3)
					ans+=binom(cnt[s1]+2,3);
				else if(s1==s2)
					ans+=binom(cnt[s1]+1,2)*cnt[s3];
				else if(s2==s3)
					ans+=binom(cnt[s3]+1,2)*cnt[s1];
				else
					ans+=(int64_t)cnt[s1]*cnt[s2]*cnt[s3];
			}
		}

		std::cout<<ans<<'\n';
	}
}