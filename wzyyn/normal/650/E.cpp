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
vector<int> e[2][N];
int n,fa[2][N],f[N];
int top,ans[N][4];
int get(int x){
	return x==f[x]?x:f[x]=get(f[x]);
}
void dfs(int T,int x){
	for (auto i:e[T][x])
		if (i!=fa[T][x]){
			fa[T][i]=x;
			dfs(T,i);
		}
}
void solve(int x){
	for (auto i:e[0][x])
		if (i!=fa[0][x]){
			solve(i);
			if (i!=fa[1][x]&&x!=fa[1][i]){
				++top;
				ans[top][0]=x;
				ans[top][1]=i;
				ans[top][2]=get(i);
				ans[top][3]=fa[1][get(i)];
			}
		}
}
int main(){
	scanf("%d",&n);
	For(T,0,1){
		For(i,1,n-1){
			int x,y;
			scanf("%d%d",&x,&y);
			e[T][x].PB(y);
			e[T][y].PB(x);
		}
		dfs(T,1);
	}
	f[1]=1;
	For(i,2,n){
		int v=fa[1][i];
		if (fa[0][i]==v||fa[0][v]==i) f[i]=v;
		else f[i]=i;
	}
	solve(1);
	printf("%d\n",top);
	For(i,1,top) For(j,0,3)
		printf("%d%c",ans[i][j],j==3?'\n':' ');
}