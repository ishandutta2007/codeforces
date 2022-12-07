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
#define all(v) v.begin(),v.end()
using namespace std;
const int N=500005;
int n,m,h,t,a[N],deg[N];
int top,ans[N];
int q[N],vis[N],inq[N];
vector<pii> e[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(pii(y,i));
		e[y].PB(pii(x,i));
		++deg[x]; ++deg[y];
	}
	For(i,1,n)
		if (a[i]>=deg[i])
			q[++t]=i,inq[i]=1;
	while (h!=t){
		int x=q[++h]; vis[x]=1;
		//cout<<x<<endl;
		for (auto i:e[x]){
			if (!vis[i.fi]) ans[++top]=i.se;
			if ((--deg[i.fi])<=a[i.fi]&&!inq[i.fi])
				q[++t]=i.fi,inq[i.fi]=1;
		}
	}
	if (t!=n) puts("DEAD");
	else{
		puts("ALIVE");
		Rep(i,top,1) cout<<ans[i]<<' ';
	}
}