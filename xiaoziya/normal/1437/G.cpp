#include<stdio.h>
#include<vector>
#include<iostream>
#include<queue>
#include<set>
#define lc(x) (x<<1)
#define rc(x) (x<<1|1)
#define mid (l+r>>1)
using namespace std;
const int maxn=300005,maxk=maxn<<2;
int n,m,dfns,tot;
int mx[maxk],id[maxn],dfn[maxn],tp[maxn],val[maxn],dep[maxn],iptson[maxn],sz[maxn],fa[maxn],nxt[maxn][27],fail[maxn],rec[maxn],A[maxn];
vector<int>v[maxn];
queue<int>q;
multiset<int>S[maxn];
string s;
void dfs1(int x,int last){
	sz[x]=1,dep[x]=dep[last]+1,fa[x]=last;
	for(int i=0;i<v[x].size();i++){
		int y=v[x][i];
		dfs1(y,x),sz[x]+=sz[y];
		if(sz[iptson[x]]<sz[y])
			iptson[x]=y;
	}
}
void dfs2(int x,int last,int t){
	dfn[x]=++dfns,id[dfns]=x,tp[x]=t;
	if(iptson[x]==0)
		return ;
	dfs2(iptson[x],x,t);
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=iptson[x])
			dfs2(v[x][i],x,v[x][i]);
}
inline void pushup(int now){
	mx[now]=max(mx[lc(now)],mx[rc(now)]);
}
void build(int l,int r,int now){
	mx[now]=-1;
	if(l==r)
		return ;
	build(l,mid,lc(now)),build(mid+1,r,rc(now));
}
void modify(int l,int r,int now,int p,int v){
	if(l==r){
		mx[now]=v;
		return ;
	}
	if(p<=mid)
		modify(l,mid,lc(now),p,v);
	else modify(mid+1,r,rc(now),p,v);
	pushup(now);
}
int query(int l,int r,int now,int L,int R){
	if(L<=l&&r<=R)
		return mx[now];
	int res=-1;
	if(L<=mid)
		res=max(res,query(l,mid,lc(now),L,R));
	if(mid<R)
		res=max(res,query(mid+1,r,rc(now),L,R));
	return res;
}
int linkqry(int x){
	int res=-1;
	while(x)
		res=max(res,query(1,tot,1,dfn[tp[x]],dfn[x])),x=fa[tp[x]];
	return res;
}
void insert(string s,int id){
	int now=1;
	for(int i=0;i<s.size();i++){
		int c=s[i]-96;
		if(nxt[now][c]==0)
			nxt[now][c]=++tot;
		now=nxt[now][c];
	}
	rec[id]=now;
}
void init(){
	for(int i=1;i<=26;i++){
		if(nxt[1][i])
			q.push(nxt[1][i]),fail[nxt[1][i]]=1;
		else nxt[1][i]=1;
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=1;i<=26;i++){
			if(nxt[x][i])
				q.push(nxt[x][i]),fail[nxt[x][i]]=nxt[fail[x]][i];
			else nxt[x][i]=nxt[fail[x]][i];
		}
	}
}
int main(){
	scanf("%d%d",&n,&m),tot=1;
	for(int i=1;i<=n;i++)
		cin>>s,insert(s,i);
	init();
	for(int i=2;i<=tot;i++)
		v[fail[i]].push_back(i);
	dfs1(1,0),dfs2(1,0,1);
	build(1,tot,1);
	for(int i=1;i<=n;i++)
		S[rec[i]].insert(0),modify(1,tot,1,dfn[rec[i]],0);
	for(int i=1,t,x,y;i<=m;i++){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&x,&y);
			S[rec[x]].erase(S[rec[x]].find(A[x])),A[x]=y,S[rec[x]].insert(A[x]);
			modify(1,tot,1,dfn[rec[x]],*S[rec[x]].rbegin());
		}
		if(t==2){
			cin>>s;
			int now=1,ans=-1;
			for(int j=0;j<s.size();j++)
				now=nxt[now][s[j]-96],ans=max(ans,linkqry(now));
			printf("%d\n",ans);
		}
	}
	return 0;
}