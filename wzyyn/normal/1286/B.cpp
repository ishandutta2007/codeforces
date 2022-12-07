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
const int N=2005;
int p[N],c[N],sz[N];
int ans[N],n,rt;
int t[N][N];
vector<int> e[N];
void dfs(int x){
	for (auto i:e[x]){
		dfs(i);
		For(j,1,sz[i])
			t[x][sz[x]+j]=t[i][j];
		sz[x]+=sz[i];
	}
	if (c[x]>sz[x]){
		puts("NO");
		exit(0);
	}
	Rep(j,sz[x],c[x]+1)
		t[x][j+1]=t[x][j];
	t[x][c[x]+1]=x;
	sz[x]++;
}
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&p[i],&c[i]);
		if (p[i]) e[p[i]].PB(i);
		else rt=i;
	}
	dfs(rt);
	For(i,1,sz[rt])
		ans[t[rt][i]]=i;
	puts("YES");
	For(i,1,n) printf("%d ",ans[i]);
}