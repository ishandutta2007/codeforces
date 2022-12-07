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
int n,m,k,a[N],b[N];
int deg[N],q[N],vis[N],fa[N];
vector<int> e[N],v[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d%d",&n,&m,&k);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) b[i]=(a[i]?a[i]:k);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
		++deg[y];
	}
	int h=0,t=0;
	For(i,1,n) if (!deg[i]) q[++t]=i;
	while (h!=t){
		int x=q[++h];
		if ((a[x]&&b[x]<a[x])||b[x]<1)
			return puts("-1"),0;
		for (auto i:e[x]){
			b[i]=min(b[i],b[x]-1);
			if (!--deg[i]) q[++t]=i;
		}
	}
	if (t!=n)
		return puts("-1"),0;
	For(i,1,n) v[b[i]].PB(i);
	For(i,1,k) fa[i]=i;
	For(i,1,k){
		for (auto j:v[i]){
			if (a[j]){
				vis[i]=1;
				continue;
			}
			int r=0;
			for (auto k:e[j])
				r=max(r,b[k]);
			r=get(r+1);
			if (r!=i) fa[r]=r+1;
			b[j]=r; vis[r]=1;
		} 
		if (vis[i])
			fa[i]=i+1;
	}
	For(i,1,k)
		if (!vis[i])
			return puts("-1"),0;
	For(i,1,n)
		printf("%d ",b[i]);
}