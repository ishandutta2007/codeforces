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
int n,p,a[N],q[N],lg[N];
vector<int> e[N];
ll ans;
void dfs(int x,int fa){
	q[++*q]=x;
	if ((*q)!=1){
		ll res=1ll*a[q[1]]*lg[(*q)-1]+a[x]+a[q[1]];
		For(j,0,18) if ((*q)>(1<<j))
			res=min(res,1ll*(j+1)*a[q[(*q)-(1<<j)]]+a[x]);
		ans+=res;
	}
	for (auto i:e[x])
		if (i!=fa) dfs(i,x);
	--*q;
}
int main(){
	scanf("%d",&n); p=1;
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) if (a[i]<a[p]) p=i;
	For(i,2,n) lg[i]=lg[(i+1)/2]+1;
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(p,0);
	printf("%lld\n",ans);
}
/*
1-1
2-1
3-2
4-2
5-3
*/