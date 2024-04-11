/*
Contest: -
Problem: Codeforces 772C
Author: tzc_wk
Time: 2020.8.26
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
int n=read(),m=read();
bool taboo[200005];
int fac[200005],faccnt=0;
vector<int> g[2005],t[200005];
int dp[2005],ans=0,id=0,a[2005],nxt[2005];
inline int dfs(int x){
	if(dp[x]) return dp[x];
	dp[x]=a[x];
	foreach(it,g[x]){
		int y=*it,val=dfs(y)+a[x];
		if(val>dp[x]) dp[x]=val,nxt[x]=y;
	}
	return dp[x];
}
inline int exgcd(int a,int b,int &x,int &y){
	if(!b){x=1;y=0;return a;}
	int d=exgcd(b,a%b,x,y);
	int z=x;x=y;y=z-y*(a/b);
	return d;
}
int main(){
	fz(i,1,n){int x=read();taboo[x]=1;}
	for(int i=1;i*i<=m;i++){
		if(m%i==0){
			fac[++faccnt]=i;
			if(m/i!=i) fac[++faccnt]=m/i;
		}
	}
	fz(i,0,m-1) if(!taboo[i]) t[__gcd(i,m)].pb(i);
	fz(i,1,faccnt) a[i]=t[fac[i]].size();
	fz(i,1,faccnt) fz(j,1,faccnt) if(fac[j]%fac[i]==0&&i!=j) g[i].pb(j);
	fz(i,1,faccnt){
		int mx=dfs(i);
		if(mx>ans) ans=mx,id=i;
	}
	int cur=id;vector<int> ans;
	do {
		foreach(it,t[fac[cur]]) ans.pb(*it);
		cur=nxt[cur];
	} while(cur);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		int pre=((i==0)?1:ans[i-1]);
		int x,y,gcd=exgcd(pre,m,x,y);
		while(x<0) x+=m;
		x=1ll*x*(ans[i]/gcd)%m;
		cout<<x<<" ";
	}
	return 0;
}