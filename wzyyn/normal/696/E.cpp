#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
const int N=100005;
vector<int> e[N];
int n,m,Q,tot,head[N];
int fa[N],dep[N],sz[N];
int top[N],dfn[N],ed[N];
int p[N],q[N],pos[N];
ll v[N];
void dfs(int x){
	sz[x]=1;
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs(i); sz[x]+=sz[i];
		}
}
void dfs(int x,int tp){
	//cout<<x<<' '<<tp<<endl;
	top[x]=tp;
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	int k=0;
	for (auto i:e[x])
		if (i!=fa[x]&&sz[i]>sz[k])
			k=i;
	if (k) dfs(k,tp);
	for (auto i:e[x])
		if (i!=fa[x]&&i!=k)
			dfs(i,i);
	ed[x]=*dfn;
}
set<pll> S[N];
pll t[N*4];
ll tg[N*4];
void build(int k,int l,int r){
	if (l==r){
		t[k]=*S[pos[l]].begin();
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=min(t[k*2],t[k*2+1]);
}
void change(int k,int l,int r,int p){
	if (l==r){
		t[k]=*S[pos[l]].begin();
		t[k].fi+=tg[k];
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	t[k]=min(t[k*2],t[k*2+1]);
	t[k].fi+=tg[k];
}
void changev(int k,int l,int r,int x,int y,int v){
	if (l==x&&r==y){
		tg[k]+=v;
		t[k].fi+=v;
		return;
	} 
	int mid=(l+r)/2;
	if (y<=mid) changev(k*2,l,mid,x,y,v);
	else if (x>mid) changev(k*2+1,mid+1,r,x,y,v);
	else{
		changev(k*2,l,mid,x,mid,v);
		changev(k*2+1,mid+1,r,mid+1,y,v);
	}
	t[k]=min(t[k*2],t[k*2+1]);
	t[k].fi+=tg[k];
} 
pll ask(int k,int l,int r,int x,int y){
	//cout<<l<<' '<<r<<' '<<x<<' '<<y<<endl;
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	pll ans(1ll<<60,1ll<<60);
	if (x<=mid) ans=min(ans,ask(k*2,l,mid,x,min(mid,y)));
	if (y>mid) ans=min(ans,ask(k*2+1,mid+1,r,max(x,mid+1),y)); 
	ans.fi+=tg[k]; return ans;
}
pll ask(int x,int y){
	pll ans(1ll<<60,1ll<<60);
	for (;top[x]!=top[y];x=fa[top[x]]){
		if (dep[top[x]]<dep[top[y]]) swap(x,y);
		ans=min(ans,ask(1,1,n,dfn[top[x]],dfn[x]));
	}
	if (dfn[x]>dfn[y]) swap(x,y);
	return min(ans,ask(1,1,n,dfn[x],dfn[y]));
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x); 
	}
	dfs(1); dfs(1,1);
	For(i,1,n) S[i].insert(pll(1ll<<60,1ll<<60));
	For(i,1,m) scanf("%d",&p[i]),v[i]=i,S[p[i]].insert(pll(v[i],i));
	build(1,1,n);
	//cout<<233<<endl;
	while (Q--){
		//cout<<Q<<endl;
		int tp,x,y;
		scanf("%d%d%d",&tp,&x,&y);
		if (tp==2) changev(1,1,n,dfn[x],ed[x],y);
		else{
			*q=0;
			int k;
			scanf("%d",&k);
			for (;k;k--){
				pll tmp=ask(x,y);
				if (tmp.fi>=(1ll<<60)) break;
				int id=q[++*q]=tmp.se;
				//cout<<id<<' '<<tmp.fi<<' '<<tmp.se<<endl;
				S[p[id]].erase(pll(v[id],id));
				S[p[id]].erase(pll(v[id]=1ll<<60,id));
				change(1,1,n,dfn[p[id]]);
			}
			For(i,0,*q) printf("%d%c",q[i],i==(*q)?'\n':' ');
		}
	}
}