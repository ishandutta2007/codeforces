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
const int N=500005;
int n,m,Q;
int p[N],ex[N],ey[N];
int T[N],tp[N],qv[N];
int key[N],fa[N],f[N][20];
int dfn[N],ed[N],pos[N],id[N];
vector<int> e[N],op[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
bool cmp(int x,int y){
	return T[x]>T[y];
}
void dfs(int x){
	dfn[x]=++*dfn;
	pos[*dfn]=x;
	for (auto i:e[x]) dfs(i);
	//cout<<x<<' '<<dfn[x]<<' '<<ed[x]<<endl;
	ed[x]=*dfn;
}
int findP(int x,int p){
	Rep(i,18,0)
		if (key[f[x][i]]>=p)
			x=f[x][i];
	return x;
}

pii t[N*4];
void build(int k,int l,int r){
	if (l==r){
		t[k]=pii(p[pos[l]],l);
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=max(t[k*2],t[k*2+1]);
} 
void change(int k,int l,int r,int p){
	if (l==r){
		t[k]=pii(0,l);
		return;
	}
	int mid=(l+r)/2;
	if (p<=mid) change(k*2,l,mid,p);
	else change(k*2+1,mid+1,r,p);
	t[k]=max(t[k*2],t[k*2+1]);
}
pii ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y)
		return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return max(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y));
}

int main(){
	scanf("%d%d%d",&n,&m,&Q);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,m) scanf("%d%d",&ex[i],&ey[i]),T[i]=Q+1;
	For(i,1,Q){
		scanf("%d%d",&tp[i],&qv[i]);
		if (tp[i]==2) T[qv[i]]=i;
	}
	For(i,1,m) op[T[i]].PB(i);
	For(i,1,m) id[i]=i;
	sort(id+1,id+m+1,cmp);
	int nd=n;
	For(i,1,n) fa[i]=i;
	For(i,1,m){
		int x=id[i];
		int p1=get(ex[x]);
		int p2=get(ey[x]);
		//cout<<p1<<' '<<p2<<endl;
		if (p1!=p2){
			key[++nd]=T[x];
			fa[p1]=fa[p2]=fa[nd]=nd;
			f[p1][0]=f[p2][0]=nd;
			e[nd].PB(p1); e[nd].PB(p2);
			//cout<<nd<<' '<<p1<<' '<<p2<<endl;
		}
	}
	For(i,1,18) For(j,1,nd)
		f[j][i]=f[f[j][i-1]][i-1];
	For(i,1,nd)
		if (!f[i][0])
			dfs(i);
	//For(i,1,nd)
	//	cout<<dfn[i]<<' '<<ed[i]<<' '<<f[i][0]<<endl;
	build(1,1,nd);
	For(i,1,Q)
		if (tp[i]==1){
			//for (int j=qv[i];j;j=f[j][0]) cerr<<j<<' '<<key[j]<<endl;
			int p=findP(qv[i],i);
			//cout<<p<<' '<<key[p]<<endl;
			pii res=ask(1,1,nd,dfn[p],ed[p]);
			change(1,1,nd,res.se);
			printf("%d\n",res.fi);
		}
}