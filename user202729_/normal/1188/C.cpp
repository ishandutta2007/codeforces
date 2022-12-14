/*
 * Total implementation time: 25 - 27 minutes + ??? minutes (find out bug) + 3 minutes (fix bug)
 * Interesting time complexity. I spent several days trying to figure out the solution because of this.
 * [I didn't see any failed test cases or read the editorial]
 */
#ifndef LOCAL
#define NDEBUG
#endif
#include<map>
#include<cassert>
#include<iostream>
#include<queue>
#include<functional>
#include<set>

int const MOD=998244353;
int inv(int x,int y=MOD){
	int a=x,b=y,ax=1,bx=0;
	while(b){
		int q=a/b;
		a%=b;
		ax-=bx*q;
		std::swap(a,b);
		std::swap(ax,bx);
	}
	if(ax<0)ax+=y;
	return ax;
}

int main(){
	std::ios::sync_with_stdio(0);std::cin.tie(0);


	int n,k;std::cin>>n>>k;
	std::vector<int> a(n);
	for(int& ai:a)std::cin>>ai;

	std::vector<int> cnt{1}; // cnt[x] = number of subsets of size k with min diff >= x
	for(int i=1;i<=k;++i)
		cnt[0]=int(cnt[0]*(n+1LL-i)%MOD*inv(i)%MOD);

	n=-1;

	// this should not change cnt[x] for x >0
	{
		int const a0=*std::min_element(begin(a),end(a));
		if(a0)
			std::transform(begin(a),end(a),begin(a),[a0](int x){return x-a0;});
	}

	std::map<int,int> avals; // a grouped by value
	for(int x:a)++avals[x];
	std::vector<std::pair<int,int>> b(begin(avals),end(avals));

	avals.clear();
	a.clear();

	std::vector<std::vector<int>> f(b.size()+1);
	while(true){
		int const d=(int)cnt.size();
		assert(b[0].first==0);
		if(d*(k-1)>b.back().first)
			break; // cnt[d]==0

		// f[i][k] = number of sequences with len=k, is a subsequence of b[:i], mindiff >= d
		f[0].assign(k+1,0);
		f[0][0]=1;
		for(unsigned i=1,j=0;i<=b.size();++i){
			while(b[i-1].first-b[j].first>=d)
				++j;

			auto const& fp=f[i-1];
			auto& fi=f[i];
			fi.resize(k+1);
			fi[0]=1;
			for(int k1=1;k1<=k;++k1){
				fi[k1]=(
						fp[k1] // if b[i-1].first is not included
						+b[i-1].second*(int64_t)f[j][k1-1] // if a[i-1] is included
					   )%MOD;
			}
		}

		cnt.push_back(f[b.size()][k]);
	}
	cnt.push_back(0);
	int ans=0;
	for(unsigned d=0;d<cnt.size()-1;++d)
		ans=int((ans+int64_t(cnt[d]-cnt[d+1])*d)%MOD);
	std::cout<<ans<<'\n';
}