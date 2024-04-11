#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=250005;
const int MX=1000005;
const int M=10500005;
struct edge{
	int to,next,v;
}e[N*2];
int head[N],deg[N],q[N];
int n,Q,T,tot,vis[N],Rt[N];
int X[N],Y[N],V[N],rt[N],pos[N];
vector<int> vece[N],vecp[N];
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot;
	e[++tot]=(edge){x,head[y],v};
	head[y]=tot;
}
int nd,flag,ls[M],rs[M],sz[M];
ll S[M],ans[N];
void insert(int &nk,int k,int l,int r,int x,int y){
	if (flag){
		nk=++nd; ls[nk]=ls[k]; rs[nk]=rs[k];
	}
	else nk=(k?k:++nd);
	S[nk]=S[k]+x*y; sz[nk]=sz[k]+y;
	if (l==r) return;
	int mid=(l+r)/2;
	if (x<=mid) insert(ls[nk],ls[k],l,mid,x,y);
	else insert(rs[nk],rs[k],mid+1,r,x,y);
	if (!sz[ls[nk]]) ls[nk]=0;
	if (!sz[rs[nk]]) rs[nk]=0;
}
ll ask(int k,int l,int r,int rk){
	if (!k) return 0;
	if (sz[k]==rk) return S[k];
	if (l==r) return 1ll*rk*l;
	int mid=(l+r)/2;
	if (sz[ls[k]]>=rk)
		return ask(ls[k],l,mid,rk);
	return ask(rs[k],mid+1,r,rk-sz[ls[k]])+S[ls[k]];
}
pll wzp[N];
pll dfs(int x,int fa,int d){
	vis[x]=T;
	pll res(0,0);
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa){
			pll tmp=dfs(e[i].to,x,d);
			assert(tmp.se<=tmp.fi);
			tmp.se=tmp.se+e[i].v;
			tmp.fi=min(tmp.fi,tmp.se);
			res.fi+=tmp.fi;	res.se+=tmp.fi;
			insert(Rt[x],Rt[x],0,MX,tmp.se-tmp.fi,1);
		}
	int del=deg[x]-d;
	res.fi+=ask(Rt[x],0,MX,del);
	res.se+=ask(Rt[x],0,MX,del-1);
	wzp[x]=res;
	return res;
	//fi:
	//se:
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		scanf("%d%d%d",&X[i],&Y[i],&V[i]);
		++deg[X[i]]; ++deg[Y[i]];
	}
	For(i,1,n-1)
		vece[min(deg[X[i]],deg[Y[i]])-1].PB(i);
	For(i,0,n-1){
		int sz=vece[i].size();
		For(j,0,vece[i].size()-1){
			int id=vece[i][j];
			insert(rt[X[id]],rt[X[id]],0,MX,V[id],1);
			insert(rt[Y[id]],rt[Y[id]],0,MX,V[id],1);
		}
		pos[i]=nd;
	}
	For(i,1,n)
		vecp[deg[i]-1].PB(i);
	Rep(i,n-1,0){
		For(j,0,vece[i].size()-1){
			int id=vece[i][j];
			add(X[id],Y[id],V[id]);
			insert(rt[X[id]],rt[X[id]],0,MX,V[id],-1);
			insert(rt[Y[id]],rt[Y[id]],0,MX,V[id],-1);
			if (!sz[rt[X[id]]]) rt[X[id]]=0;
			if (!sz[rt[Y[id]]]) rt[Y[id]]=0;
		}
		for (;nd>(i?pos[i-1]:0);--nd)
			sz[nd]=S[nd]=ls[nd]=rs[nd]=0;
		For(j,0,vecp[i].size()-1)
			q[++*q]=vecp[i][j];
		For(j,1,*q) Rt[q[j]]=rt[q[j]];
		int tmp=nd; ++T; flag=1;
		sort(q+1,q+*q+1);
		For(j,1,*q)
			if (vis[q[j]]!=T)
				ans[i]+=dfs(q[j],0,i).fi;
		flag=0;
	}
	For(i,0,n-1)
		printf("%lld ",ans[i]);
}
/*
f[x][0],f[x][1];
*/