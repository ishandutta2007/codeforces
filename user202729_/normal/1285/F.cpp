// Mobius transformation. Surprisingly fast (for 10**5 distinct numbers on my machine it only take 0.2s
// (twice that with 32 bit)
//
// Update: TLE? Since I have no idea what's the failing test, I'd just add some optimizations. On my machine
// they doesn't make the run time with the (10**5 distinct numbers) faster at all.
#ifndef LOCAL
#define NDEBUG
#endif
#include<cassert>
#include<iostream>
#include<vector>
#include<climits>
#include<cmath>

auto ceildiv(auto x,auto y){
	return (x+y-1)/y;
};

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);
	int n;std::cin>>n;
	std::vector<char> have;
	std::vector<int> a(n);
	{
		int maxx=0;
		for(int& x:a){ std::cin>>x; maxx=std::max(maxx,x); }
		have.resize(maxx+1);
		for(int x:a) have[x]=true;
		a.clear();
		for(unsigned x=0;x<have.size();++x) if(have[x]) a.push_back(x);
	}

	if(a.size()==1) { std::cout<<a[0]<<'\n'; return 0; }

	int const maxsieve=std::max((int)have.size(),4);
	std::vector<char> iscomposite(maxsieve);
	std::vector<int> mobius(maxsieve);
	mobius[1]=1;
	for(int i=2;i<maxsieve;++i)if(not iscomposite[i]){
		mobius[i]=-1;
		for(int j=2;i*j<maxsieve;++j){
			iscomposite[i*j]=true;
			mobius[i*j]=j%i==0 ? 0 : -mobius[j];
		}
	}

	std::vector<std::vector<int>> amult(have.size());
	for(unsigned x=1;x<amult.size();++x)
		for(unsigned y=x;y<have.size();y+=x)
			if(have[y]) amult[x].push_back(y);

	int64_t const maxlcm=a.back()*(int64_t)a.end()[-2];
	int64_t k=0;
	for(int64_t step=1LL<<50;step!=0;step>>=1){
		k+=step;
		if(k>maxlcm){
invalid_k:
			k-=step;
			continue;
		}

		int64_t cnt=0;

		for(int d=1;d<(int)have.size();++d)
		if((double)d*k<=(double)INT64_MAX/2 and d*k<=have.size()*(int64_t)have.size())
		for(int e=1;d*e<(int)have.size();++e)if(mobius[e]!=0){
			int64_t tmp=0;
			int64_t lastminj=-1, lastval=-1;
			for(int i:amult[d*e]){
				auto minj=d*e * (int64_t)ceildiv(k, e*(int64_t)i);
				if(minj!=lastminj){
					lastminj=minj;
					lastval=int(end(amult[d*e]) - std::lower_bound(begin(amult[d*e]), end(amult[d*e]), minj));
				}
				tmp+=lastval;
			}
			cnt+=tmp*mobius[e];
		}

		if(cnt==0) goto invalid_k;
		assert(cnt>0);
	}
	std::cout<<k<<'\n';
}