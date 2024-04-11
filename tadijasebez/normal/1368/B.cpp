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
template<typename T>void rd(vector<T>&v){for(T&i:v)rd(i);}

ll p10(ll x){
	ll x2=x*x;
	ll x4=x2*x2;
	ll x8=x4*x4;
	return x8*x2;
}
int main(){
	ll k;rd(k);
	for(ll i=1;;i++){
		if(p10(i+1)>=k){
			ll now=p10(i);
			vector<int> sz(10,i);
			while(now<k){
				now/=i;
				now*=i+1;
				sz.pop_back();
			}
			while(sz.size()<10)sz.pb(i+1);
			string o="codeforces";
			for(int j=0;j<10;j++){
				for(int z=0;z<sz[j];z++){
					printf("%c",o[j]);
				}
			}
			printf("\n");
			return 0;
		}
	}
	return 0;
}