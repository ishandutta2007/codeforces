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
vector<int> e[N];
vector<pii> ans;
int n,mx;
void dfs(int x,int y,int d){
	int tmp=d;
	ans.PB(pii(x,d));
	for (auto i:e[x]) if (i!=y){
		if (d==mx){
			d=mx-e[x].size();
			ans.PB(pii(x,d));
		}
		dfs(i,x,++d);
		ans.PB(pii(x,d));
	}
	if (y&&d!=tmp-1)
		ans.PB(pii(x,tmp-1));
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	For(i,1,n) mx=max(mx,(int)e[i].size());
	dfs(1,0,0);
	printf("%d\n",ans.size());
	for (auto i:ans) printf("%d %d\n",i.fi,i.se);
}