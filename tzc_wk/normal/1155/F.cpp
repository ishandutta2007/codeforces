/*
Contest: -
Problem: Codeforces 1155F
Author: tzc_wk
Time:
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n=read(),m=read(),u[205],v[205];
bool vis[205];
int to[205],ecnt=0,nxt[205],hd[205];
inline void ae(int x,int y){
	to[++ecnt]=y;
	nxt[ecnt]=hd[x];
	hd[x]=ecnt;
}
int dfn[15],low[15],tim=0;
bool flg=0;
inline void tarjan(int x,int f){
	dfn[x]=low[x]=++tim;
	for(int i=hd[x];i;i=nxt[i]){
		int y=to[i];
		if(!dfn[y]){
			tarjan(y,x);
			low[x]=min(low[x],low[y]);
			if(low[y]>dfn[x]) flg=1;
		}
		else if(y!=f) low[x]=min(low[x],dfn[y]);
	}
}
signed main(){
	srand(20060729);
	fz(i,1,m){
		u[i]=read(),v[i]=read();
	}
	int M=200000;fill0(vis);
	vector<int> ans;
	fz(i,1,m) ans.push_back(i);
	while(M--){
		if(M%1000==0){
			fz(i,1,m) vis[i]=0;
		}
		int id=rand()%m+1,tp=rand()%5;
		if(tp) vis[id]=1;
		else if(!vis[id]) vis[id]=0;
		fill0(hd);fill0(nxt);fill0(to);ecnt=0;
		fz(i,1,m) if(!vis[i]) ae(u[i],v[i]),ae(v[i],u[i]);
		fill0(dfn);fill0(low);tim=0;
		flg=0;
		fz(i,1,n) if(!dfn[i]) tarjan(i,0);
		if(flg) vis[id]=0;
		vector<int> t;
		fz(i,1,m) if(vis[i]==0) t.push_back(i);
		if(t.size()<ans.size()) ans=t;
	}
	cout<<ans.size()<<endl;
	foreach(it,ans) cout<<u[*it]<<" "<<v[*it]<<endl;
	return 0;
}