// author: xay5421
// created: Mon Nov 15 17:42:23 2021
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
template<class T>void rd(T&x){int f=0,c;while(!isdigit(c=getchar()))f^=!(c^45);x=(c&15);while(isdigit(c=getchar()))x=x*10+(c&15);if(f)x=-x;}
template<class T>void pt(T x,int c=-1){if(x<0)putchar('-'),x=-x;if(x>9)pt(x/10);putchar(x%10+48);if(c!=-1)putchar(c);}
template<class T>void umin(T&x,const T&y){if(y<x)x=y;}
template<class T>void umax(T&x,const T&y){if(x<y)x=y;}
using LL=long long;
const int N=1000005;
const LL INFLL=0X3F3F3F3F3F3F3F3FLL;
int n;
LL K;
pair<LL,int>a[N];
map<LL,vector<int> >mp;
int main(){
#ifdef xay5421
	freopen("a.in","r",stdin);
#endif
	rd(n),rd(K);
	LL g=0;
	rep(i,1,n)rd(a[i].first),g=__gcd(g,a[i].first);
	rep(i,1,n)rd(a[i].second);
	if(g==1)puts("0"),exit(0);
	vector<LL>primes;
	{
		LL x=g;
		for(LL i=2;i<=x/i;++i)if(x%i==0){
			primes.pb(i);
			while(x%i==0)x/=i;
		}
		if(x>1)primes.pb(x);
	}
	auto norm=[&](LL x){
		LL y=1;
		for(auto&p:primes){
			while(x%p==0)x/=p,y*=p;
		}
		return y;
	};
	rep(i,1,n)mp[norm(a[i].first)].pb(a[i].second);
	vector<vector<LL> >dp(SZ(primes)+1,vector<LL>(1<<SZ(primes),INFLL));
	dp[0][0]=0;
	for(auto&cur:mp){
		if(SZ(cur.second)>SZ(primes)){
			sort(cur.second.begin(),cur.second.end());
			cur.second.resize(SZ(primes));
		}
		vector<LL>ws(SZ(primes));
		rep(i,0,SZ(primes)-1){
			ws[i]=1;
			while(cur.first/ws[i]%primes[i]==0)ws[i]*=primes[i];
		}
		vector<LL>num(1<<SZ(primes));
		num[0]=1;
		rep(i,1,(1<<SZ(primes))-1)num[i]=num[i&(i-1)]*ws[__builtin_ctz(i)];
		for(auto&now_e:cur.second){
			per(i,SZ(primes)-1,0){
				rep(j,0,(1<<SZ(primes))-1)if(dp[i][j]<INFLL){
					int j_=(1<<SZ(primes))-1-j;
					for(int k=j_;k;--k&=j_){
						if(num[k]<=K){
							umin(dp[i+1][j|k],dp[i][j]+now_e);
						}
					}
				}
			}
		}
	}
	LL ans=INFLL;
	rep(i,1,SZ(primes))if(dp[i][(1<<SZ(primes))-1]<INFLL)umin(ans,dp[i][(1<<SZ(primes))-1]*i);
	if(ans==INFLL)puts("-1");
	else printf("%lld\n",ans);
	return 0;
}