#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
const int N=505;
ll a[N];
int main(){
	int n=ri();
	ll ans=0;
	for(int i=1;i<=n;i++)rd(a[i]);
	for(int i=1;i<=n;++i){
		ans=max(ans,a[i]);
		for(int j=i+1;j<=n;++j){
			ans=max(ans,a[i]|a[j]);
			for(int k=j+1;k<=n;++k){
				ans=max(ans,a[i]|a[j]|a[k]);
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}