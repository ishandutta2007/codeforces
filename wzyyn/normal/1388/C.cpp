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
const int N=100005;
int n,m,flag;
int p[N],h[N],a[N];
vector<int> e[N];
void dfs(int x,int fa){
	a[x]=0;
	for (auto i:e[x]) if (i!=fa){
		dfs(i,x);
		a[x]+=a[i];
		p[x]+=p[i];
	}
	if ((p[x]+h[x])%2==1||h[x]<-p[x]||h[x]>p[x]) flag=1;
	int v=(p[x]+h[x])/2;
	//cout<<a[x]<<' '<<p[x]<<' '<<h[x]<<' '<<x<<endl;
	if (v<a[x]) flag=1;
	a[x]=v;
}
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,1,n) scanf("%d",&h[i]);
	flag=0;
	For(i,1,n) e[i].resize(0);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	dfs(1,0);
	puts(flag?"NO":"YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}