#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define For(i,x,y)	for(ll i=(x);i<=(y);++i)
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x;
}
const ll N = 30,M = 600000;
ll n,m,x[M],y[M],w[M],mp[N][N],ww[N][N],tims[M],ff[M],res[M],cur[M],a[M];
int main(){
	n = read(); m = read();
	For(i,1,m) y[i] = read(),x[i] = read(),w[i] = read(),mp[x[i]][y[i]]=1,ww[x[i]][y[i]]+=w[i];
	For(k,1,n) For(i,1,n) For(j,1,n) mp[i][j] |= mp[i][k]&&mp[k][j]; 
	For(S,0,(1<<n)-1){
		For(j,1,n) if(!(S>>(j-1)&1)){
			bool Ok = 1,Any = 1;
			For(i,1,n) if(mp[i][j])		Any &= S>>(i-1)&1;
			For(i,1,n)if (S>>(i-1)&1)	res[S]+=ww[i][j]; 
			if (Any)tims[S] |= 1<<(j-1);
		}
	}
	memset(ff,30,sizeof ff);
	ff[0] = 0;	ll tt = (1<<n);
	For(S,0,tt-1){
		ff[S] += res[S];
		for(ll T = tims[S];T;T = (T-1)&tims[S])
			if (ff[S^T] > ff[S]){
				ff[S^T] = ff[S];
				cur[S^T] = S;
			}
	}ll t=18;
	for(ll S = (1<<n)-1;S;S = cur[S]){
		For(i,1,n)if(!(S>>(i-1)&1)&&!a[i])a[i] = t;
		--t;
//		For(i,1,n)if (S>>(i-1)&1)cout<<i<<' ';puts(""); 
//		For(i,1,n)cout<<a[i]<<' ';puts("");
	}
		For(i,1,n) if(!a[i]) a[i] = t;
		For(i,1,n)cout<<a[i]<<' ';
}
/*

*/