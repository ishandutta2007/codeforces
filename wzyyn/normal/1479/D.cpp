#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

const int N=300005;
int n,Q,a[N];
int dep[N],fa[N][20];

ull key[N];
vector<int> e[N];
ull rnd(){
	ull x=0;
	For(i,1,64) x=x*233+rand();
	return x;
}

const int M=6000005;
int ls[M],rs[M],nd,rt[N];
ull hsh[M];

void insert(int &nk,int k,int l,int r,int p){
	nk=++nd; hsh[nk]=hsh[k]^key[p];
	ls[nk]=ls[k]; rs[nk]=rs[k];
	if (l==r) return;
	int mid=(l+r)/2;
	if (p<=mid) insert(ls[nk],ls[k],l,mid,p);
	else insert(rs[nk],rs[k],mid+1,r,p);
}
int find(int k1,int k2,int l,int r,int x,int y){
	if (hsh[k1]==hsh[k2]) return -1;
	if (l==r) return l;
	int mid=(l+r)/2;
	if (x<=mid){
		int re=find(ls[k1],ls[k2],l,mid,x,y);
		if (re!=-1) return re;
	}
	if (y>mid)
		return find(rs[k1],rs[k2],mid+1,r,x,y);
	return -1;
}
void dfs(int x){
	insert(rt[x],rt[x],1,n,a[x]);
	for (auto i:e[x])
		if (i!=fa[x][0]){
			fa[i][0]=x;
			dep[i]=dep[x]+1;
			rt[i]=rt[x];
			dfs(i);
		}
}
int LCA(int x,int y){
	if (dep[x]<dep[y]) swap(x,y);
	int dif=dep[x]-dep[y];
	Rep(i,18,0)
		if (dif&(1<<i))
			x=fa[x][i];
	Rep(i,18,0)
		if (fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return x==y?x:fa[x][0];
}
int main(){
	srand(time(NULL));
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) key[i]=rnd();
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
		e[y].PB(x);
	}
	dfs(1);
	For(i,1,18) For(j,1,n)
		fa[j][i]=fa[fa[j][i-1]][i-1];
	while (Q--){
		int x,y,l,r;
		scanf("%d%d%d%d",&x,&y,&l,&r);
		int la=nd,tmp=rt[x],L=LCA(x,y);
		insert(tmp,tmp,1,n,a[L]);
		printf("%d\n",find(rt[y],tmp,1,n,l,r));
		nd=la;
	}
}