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
const int mod=1e9+7;
const int lim=2e6;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}
int main(){
	for(int t=ri();t--;){
		int n,p;rd(n,p);
		vector<int> a(n);
		for(int&i:a)rd(i);
		sort(a.rbegin(),a.rend());
		int las=-1;ll now=0;
		int ans=0;
		for(int i:a){
			if(las!=-1){
				if(p!=1&&now!=0){
					while(las>i&&now<lim)now*=p,las--;
				}
			}
			if(now>0){
				now--;
				ans=sub(ans,powmod(p,i));
			}else{
				now++;
				ans=add(ans,powmod(p,i));
			}
			las=i;
		}
		printf("%i\n",ans);
	}
	return 0;
}