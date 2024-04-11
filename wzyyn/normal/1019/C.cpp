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
const int N=1000005;
int n,m,ans[N],vis[N];
vector<int> e[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y);
	}
	For(i,1,n) if (!vis[i])
		for (auto j:e[i]) if (j>i) vis[j]=1;
	Rep(i,n,1) if (!vis[i]){
		ans[++*ans]=i;
		for (auto j:e[i]) vis[j]=1;
	}
	printf("%d\n",*ans);
	For(i,1,*ans) printf("%d ",ans[i]);
}