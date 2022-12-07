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
const int N=3005;
int n,ans,sum,a[N];
int sz[N],fa[N];
struct edge{
	int x,y,v;
	bool operator <(const edge &a)const{
		return v<a.v;
	}
}e[N];
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1) scanf("%d%d%d",&e[i].x,&e[i].y,&e[i].v);
	sort(e+1,e+n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) sz[i]=1,fa[i]=i,sum+=a[i];
	For(i,1,n-1){
		ans=e[i].v;
		int x=get(e[i].x),y=get(e[i].y);
		fa[x]=y; sz[y]+=sz[x]; a[y]+=a[x];
		if (sz[y]>sum-a[y]) break;
	}
	printf("%d\n",ans);
}