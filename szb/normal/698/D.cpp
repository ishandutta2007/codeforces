#include<stdio.h>
#include<string.h>
#include<string>
#include<math.h>
#include<iostream>
#include<bitset>
#include<map>
#include<vector>
#include<set>
#include<queue>
#include<algorithm>
#include<limits.h>
#include<stdlib.h>
#include<time.h>
#define ll long long
#define maxn 200010
#define For(i,x,y) for(ll i=x;i<=y;i++)
#define FOr(i,x,y) for(ll i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
inline void write(ll x){if(x<10) putchar(x+48);else write(x/10),putchar(x%10+48);}
inline void writeln(ll x){if(x<0) x=-x,putchar('-');write(x);putchar('\n');}
ll n,m,x[maxn],y[maxn],X[maxn],Y[maxn],r[maxn],vis[maxn],tot,clck,ans;
vector<ll>v[10][1010];
ll gcd(ll a,ll b){	return b?gcd(b,a%b):a;}
inline ll get(ll x){	return x>0?1:(x<0?-1:0);	}
bool in(ll i,ll j,ll k){
	ll a=x[j]-X[i],b=y[j]-Y[i],c=x[k]-X[i],d=y[k]-Y[i];
	if ((get(a)!=get(c))||(get(b)!=get(d)))	return 0;
	if ((abs(a)>abs(c))||(abs(b)>abs(d)))	return 0;
	return a*d==b*c;
}
bool dfs(ll x){
	if (tot>m)	return 0;
	ll now=r[tot++];
	for(ll i=0;i<v[now][x].size();i++){
		ll to=v[now][x][i];
		if (vis[to]!=clck&&!dfs(to))	return 0;
	}vis[x]=clck;
	return 1;
}
int main(){
	m=read();	n=read();
	For(i,1,m)	X[i]=read(),Y[i]=read();
	For(i,1,n)	x[i]=read(),y[i]=read();
	For(i,1,m)	For(j,1,n)	For(k,1,n)	if (j!=k&&in(i,k,j)){
		v[i][j].push_back(k);
		if (v[i][j].size()>m)	break;
	}
	For(i,1,n){
		For(j,1,m)	r[j]=j;
		do{
			++clck;	tot=1;
			if (dfs(i)){	ans++;		break;	}
		}while(next_permutation(r+1,r+m+1));
	}writeln(ans);
}/*
2 4
-2 -1
4 5
4 2
2 1
4 -1
1 -1
*/