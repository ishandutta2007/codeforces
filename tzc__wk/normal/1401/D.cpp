/*
Contest: Codeforces Round #665 (Div.2)
Problem: Codeforces Round #665 (Div.2) D
Author: tzc_wk
Time: 2020.8.21
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
#define int long long
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
const int MOD=1e9+7;
int n;
vector<int> g[100005];
int siz[100005],pth[100005],p[100005];
inline void dfs(int x,int f){
	siz[x]=1;
	foreach(it,g[x]){
		int y=*it;if(y==f) continue;
		dfs(y,x);siz[x]+=siz[y];
	}
	pth[x]=siz[x]*(n-siz[x]);
}
inline void solve(){
	n=read();fz(i,1,n) g[i].clear();fill0(pth);fill0(p);fill0(siz);
	fz(i,1,n-1){
		int u=read(),v=read();
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1,0);
	sort(pth+2,pth+n+1);
	int m=read();fz(i,1,m) p[i]=read();
	if(m>=n-1){
		sort(p+1,p+m+1);fz(i,n,m) p[n-1]=p[n-1]*p[i]%MOD;
	}
	else{
		fz(i,m+1,n-1) p[i]=1;sort(p+1,p+n);
	}
	int ans=0;
	fz(i,1,n-1) ans=(ans+pth[i+1]%MOD*p[i]%MOD)%MOD;
	cout<<ans<<endl;
}
signed main(){
	int T=read();while(T--) solve();
}