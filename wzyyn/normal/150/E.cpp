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
int d[N],dep[N];
int head[N],tot,n,L,R,q[N];
int fa[N],fav[N],hson[N],S[N];
int st[N],rt[N],ans0,ans1,flg;
struct edge{
	int to,next,v;
}e[N*2];
int ls[N*4],rs[N*4],nd;
pii t[N*4];
void build(int &k,int l,int r){
	k=++nd; t[k]=pii(-(1<<30),-(1<<30));
	if (l==r) return;
	int mid=(l+r)/2;
	build(ls[k],l,mid);
	build(rs[k],mid+1,r);
} 
void change(int k,int l,int r,int p,pii v){
	t[k]=max(t[k],v);
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) change(ls[k],l,mid,p,v);
	else change(rs[k],mid+1,r,p,v);
}
pii ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(ls[k],l,mid,x,y);
	if (x>mid) return ask(rs[k],mid+1,r,x,y);
	return max(ask(ls[k],l,mid,x,mid),ask(rs[k],mid+1,r,mid+1,y));
}
void add(int x,int y,int v){
	e[++tot]=(edge){y,head[x],v};
	head[x]=tot; 
} 
void dfs1(int x){
	d[x]=0;
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]){
			dep[e[i].to]=dep[x]+1;
			fa[e[i].to]=x;
			fav[e[i].to]=e[i].v;
			dfs1(e[i].to);
			if (d[e[i].to]+1>d[x]){
				hson[x]=e[i].to;
				d[x]=d[e[i].to]+1;
			}
		}
}
void check(int x,int v){
	//cout<<x<<' '<<v<<' '<<st[x]<<' '<<dep[x]+d[x]<<' '<<S[x]<<endl;
	if (hson[fa[x]]!=x){
		st[x]=dep[x];
		build(rt[x],dep[x],dep[x]+d[x]);
	}
	if (hson[x]){
		st[hson[x]]=st[x];
		S[hson[x]]=S[x]+(fav[hson[x]]>=v?1:-1);
		rt[hson[x]]=rt[x];
		check(hson[x],v);
	}
	if (d[x]>=L){
		pii v=ask(rt[x],st[x],dep[x]+d[x],dep[x]+L,min(dep[x]+R,dep[x]+d[x]));
		//cout<<v.fi<<' '<<v.se<<endl;
		if (v.fi+S[x]-2*S[x]>=0)
			flg=1,ans0=x,ans1=v.se;
	}
	change(rt[x],st[x],dep[x]+d[x],dep[x],pii(S[x],x));
	for (int i=head[x];i;i=e[i].next)
		if (e[i].to!=fa[x]&&e[i].to!=hson[x]){
			S[e[i].to]=S[x]+(fav[e[i].to]>=v?1:-1);
			check(e[i].to,v);
			For(j,1,min(R,d[e[i].to]+1)){
				pii v=ask(rt[e[i].to],dep[e[i].to],dep[e[i].to]+d[e[i].to],dep[x]+j,dep[x]+j);
				int vl=dep[x]+max(0,L-j),vr=dep[x]+min(d[x],R-j);
				if (vl<=vr){
					pii vv=ask(rt[x],st[x],dep[x]+d[x],vl,vr);
					if (vv.fi+v.fi-2*S[x]>=0)
						flg=1,ans0=v.se,ans1=vv.se;
				}
			}
			For(j,1,min(R,d[e[i].to]+1)){
				pii v=ask(rt[e[i].to],dep[e[i].to],dep[e[i].to]+d[e[i].to],dep[x]+j,dep[x]+j);
				change(rt[x],st[x],dep[x]+d[x],dep[x]+j,v);
			}
		}
}
bool check(int v){
	for (;nd;ls[nd]=rs[nd]=0,--nd);
	flg=0;
	check(1,v);
	//printf("%d ",v); puts(flg?"WZP":"YYN");
	return flg;
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d%d",&n,&L,&R);
	For(i,1,n-1){
		int x,y,v;
		scanf("%d%d%d",&x,&y,&v);
		add(x,y,v);
		add(y,x,v);
		q[++*q]=v;
	}
	dfs1(1);
	sort(q+1,q+n);
	int l=1,r=n-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(q[mid])) l=mid+1;
		else r=mid-1;
	}
	printf("%d %d\n",ans0,ans1);
}