#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
const int N=200005;
int n,m;
LL L,R;
multiset<tuple<int,int> >S;
vector<int>d[N];
int main(){
	scanf("%d%d%lld%lld",&n,&m,&L,&R);
	for(int i=1;i<N;++i)for(int j=i;j<N;j+=i)d[j].pb(i);
	int l=m,r=m;
	rep(x1,1,n){
		LL ll=(L+x1-1)/x1,rr=R/x1;
		if(ll>rr){
			puts("-1");
			continue;
		}
		auto ps=[&](int x){
			for(auto&y:d[x]){
				S.insert({y,x});
			}
		};
		auto pop=[&](int x){
			for(auto&y:d[x]){
				S.erase(S.find({y,x}));
			}
		};
		while(ll<=l){
			ps(l--);
		}
		while(rr<r){
			pop(r--);
		}
		tuple<int,int,int,int>ans={-1,-1,-1,-1};
		for(auto&x:d[x1]){
			auto it=S.lower_bound({x+1,0});
			if(it!=S.end()&&1LL*x1/x*get<0>(*it)<=n){
				ans={x1,get<1>(*it),x1/x*get<0>(*it),get<1>(*it)/get<0>(*it)*x};
				break;
			}
		}
		if(get<0>(ans)==-1)puts("-1");
		else printf("%d %d %d %d\n",get<0>(ans),get<1>(ans),get<2>(ans),get<3>(ans));
	}
	return 0;
}