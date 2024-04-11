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
map<int,int> e[N];
int n,deg[N],ans[N],T;
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		++deg[x]; ++deg[y];
		e[x][y]=e[y][x]=i;
	}
	For(i,1,n-1) ans[i]=-1;
	For(i,1,n)
		if (deg[i]>=3)
			for (auto j:e[i])
				if (ans[j.se]==-1) ans[j.se]=T++;
	For(i,1,n)
		if (deg[i]<3)
			for (auto j:e[i])
				if (ans[j.se]==-1) ans[j.se]=T++;
	For(i,1,n-1)
		printf("%d\n",ans[i]);
}