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
const int N=200005;
int T,dfn[N],ed[N],n,rt,Q;
int ch[N][2],fa[N],id[N],tg[N];
vector<int> e[N];
struct node{
	int v,mn,mx;
	node(){
		mn=1<<30;
		mx=-(1<<30);
	}
}t[N];
void add(int k,int v){
	tg[k]+=v;
	t[k].v+=v;
	t[k].mn+=v;
	t[k].mx+=v;
}
void pushup(int k){
	int ls=ch[k][0],rs=ch[k][1];
	t[k].mn=min(t[k].v,min(t[ls].mn,t[rs].mn));
	t[k].mx=max(t[k].v,max(t[ls].mx,t[rs].mx));
}
void pushdown(int k){
	if (!tg[k]) return;
	if (ch[k][0]) add(ch[k][0],tg[k]);
	if (ch[k][1]) add(ch[k][1],tg[k]);
	tg[k]=0;
}
void rotate(int x){
	int y=fa[x],z=fa[y];
	int l=(ch[y][1]==x),r=l^1;
	if (z) ch[z][ch[z][1]==y]=x;
	fa[x]=z; fa[y]=x; fa[ch[x][r]]=y;
	ch[y][l]=ch[x][r]; ch[x][r]=y;
	pushup(y); pushup(x); 
}
void Down(int x){
	if (fa[x]) Down(fa[x]); 
	pushdown(x);
}
void splay(int x,int aim){
	Down(x);
	for (;fa[x]!=aim;rotate(x)){
		int y=fa[x],z=fa[y];
		if (z!=aim) rotate((ch[y][1]==x)^(ch[z][1]==y)?x:y);
	}
	if (aim==0) rt=x;
}

int pre(int x){
	splay(x,0);
	for (x=ch[x][0];ch[x][1];x=ch[x][1]);
	return x;
}
int suf(int x){
	splay(x,0);
	for (x=ch[x][1];ch[x][0];x=ch[x][0]);
	return x;
}
int find(int x,int v){
	//cout<<x<<' '<<t[x].mn<<' '<<t[x].mx<<' '<<v<<endl; 
	pushdown(x);
	int l=ch[x][0],r=ch[x][1];
	if (t[r].mn<=v&&v<=t[r].mx) return find(r,v);
	return t[x].v==v?x:find(l,v);	
}
void get(int x,int y){
	splay(x,0);
	splay(y,x);
}
void dfs(int x,int d){
	dfn[x]=++T; id[T]=x; t[T].v=d;
	for (auto i:e[x]) dfs(i,d+1);
	ed[x]=++T; id[T]=x; t[T].v=d;
}
void build(int &k,int l,int r,int f){
	fa[k=(l+r)/2]=f;
	if (l<k) build(ch[k][0],l,k-1,k);
	if (k<r) build(ch[k][1],k+1,r,k);
	pushup(k);
}
int main(){
	//freopen("1.in","r",stdin);
	scanf("%d%d",&n,&Q);
	For(i,1,n){
		int cnt,x;
		scanf("%d",&cnt);
		for (;cnt--;){
			scanf("%d",&x);
			e[i].PB(x);
		}
	}
	++T; dfs(1,1); ++T;
	build(rt,1,T,0);
	while (Q--){
		int tp,x,y;
		scanf("%d%d",&tp,&x);
		if (tp==1){
			scanf("%d",&y);
			get(x=dfn[x],y=dfn[y]);
			int p=t[ch[y][ch[x][0]==y]].mn;
			printf("%d\n",t[x].v+t[y].v-2*min(min(t[x].v,t[y].v),p-1));
		}
		if (tp==2){
			scanf("%d",&y);
			get(1,dfn[x]);
			//cout<<233<<endl;
			int p=id[find(ch[dfn[x]][0],t[dfn[x]].v-y)];
			int l=pre(dfn[x]),r=suf(ed[x]),pp;
			//cout<<233<<' '<<p<<' '<<l<<' '<<r<<endl;
			get(l,r); pp=ch[r][0];
			//cout<<233<<' '<<p<<' '<<l<<' '<<r<<endl;
			fa[pp]=ch[r][0]=0;
			pushup(r); pushup(l);
			r=ed[p]; l=pre(r); get(l,r);
			//cout<<233<<' '<<p<<' '<<l<<' '<<r<<endl;
			fa[pp]=r; ch[r][0]=pp; add(pp,-y+1);
			pushup(r); pushup(l); 
		}
		if (tp==3)
			printf("%d\n",id[find(rt,x+1)]);
	} 
}