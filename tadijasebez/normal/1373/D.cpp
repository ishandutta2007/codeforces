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

ll Mx(vector<int> arr){
	ll mn=0,mx=0,sum=0;
	for(int i:arr){
		sum+=i;
		mx=max(mx,sum-mn);
		mn=min(mn,sum);
	}
	return mx;
}
int main(){
	for(int t=ri();t--;){
		int n=ri();
		vector<int> a(n);
		for(int&i:a)rd(i);
		ll ans=0;
		for(int i=0;i<n;i+=2)ans+=a[i];
		vector<int> b,c;
		for(int i=1;i<n;i+=2)b.pb(a[i]-a[i-1]);
		for(int i=2;i<n;i+=2)c.pb(a[i-1]-a[i]);
		printf("%lld\n",ans+max(Mx(b),Mx(c)));
	}
	return 0;
}