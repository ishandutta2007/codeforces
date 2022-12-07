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
int n,m,top;
int a[N],b[N],fa[N];
ll ans;
pii e[N];
bool cmp(pii x,pii y){
	return a[x.fi]+b[x.se]>a[y.fi]+b[y.se];
}
int get(int x){
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m) scanf("%d",&b[i]);
	For(i,1,n){
		int x,y;
		scanf("%d",&x);
		For(j,1,x){
			scanf("%d",&y);
			e[++top]=pii(i,y);
			ans+=a[i]+b[y];
		}
	}
	sort(e+1,e+top+1,cmp);
	For(i,1,n+m) fa[i]=i;
	For(i,1,top){
		int x=get(e[i].fi);
		int y=get(e[i].se+n);
		if (x!=y){
			fa[x]=y;
			ans-=a[e[i].fi]+b[e[i].se];
		}
	}
	cout<<ans<<endl;
}