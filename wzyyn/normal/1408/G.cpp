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
const int N=1505;
const int mo=998244353;
int n,m,a[N][N];
int fa[N],sz[N],S[N];
int f[N][N],tmp[N];
pii e[N*N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int x,int y){
	memset(tmp,0,sizeof(tmp));
	For(i,1,sz[x]) For(j,1,sz[y])
		tmp[i+j]=(tmp[i+j]+1ll*f[x][i]*f[y][j])%mo;
	memcpy(f[x],tmp,sizeof(f[x]));
	sz[x]+=sz[y];
	S[x]+=S[y];
	fa[y]=x;
}
bool cmp(pii x,pii y){
	return a[x.fi][x.se]<a[y.fi][y.se];
}
int main(){
	scanf("%d",&n);
	For(i,1,n) For(j,1,n) scanf("%d",&a[i][j]);
	For(i,1,n) For(j,i+1,n) e[++m]=pii(i,j);
	sort(e+1,e+m+1,cmp);
	For(i,1,n) fa[i]=i,sz[i]=1,S[i]=0,f[i][1]=1;
	For(i,1,m){
		int x=get(e[i].fi);
		int y=get(e[i].se);
		if (x!=y) merge(x,y);
		++S[x];
		if (S[x]==sz[x]*(sz[x]-1)/2)
			f[x][1]=(f[x][1]+1)%mo;
	}
	For(i,1,n)
		cout<<f[get(1)][i]<<' ';
}