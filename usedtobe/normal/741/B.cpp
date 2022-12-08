#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
const int N=1111;
int f[N],a[N],b[N],w[N],v[N],g[N],fa[N];
int W,n,m;
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
int main() {
	scanf("%d%d%d",&n,&m,&W);
	rep(i,1,n)scanf("%d",&w[i]);
	rep(i,1,n)scanf("%d",&v[i]);
	rep(i,1,n)fa[i]=i;
	rep(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		int p=get(x),q=get(y);
		fa[p]=q;
	}
	rep(i,1,n)a[get(i)]+=w[i],b[get(i)]+=v[i];
	rep(i,1,n)if(a[i]){
		memcpy(g,f,sizeof g);
		dep(j,W,a[i])g[j]=max(f[j-a[i]]+b[i],g[j]);
		rep(_,1,n)if(get(_)==get(i)){
			dep(j,W,w[_])g[j]=max(f[j-w[_]]+v[_],g[j]);
		}
		memcpy(f,g,sizeof f);
	}
	int mx=0;rep(i,0,W)mx=max(mx,f[i]);
	cout<<mx;
	return 0;
}