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
int n,fl,vis[N];
void dfs1(int x,int fa,int d){
	if (e[x].size()==1&&d) fl=1;
	for (auto i:e[x]) if (i!=fa)
		dfs1(i,x,d^1);
}
void checkmn(){
	int rt=1;
	for (;e[rt].size()!=1;++rt);
	dfs1(rt,0,0);
	printf(fl?"3":"1");
}
void checkmx(){
	int ans=n-1;
	For(i,1,n) if (e[i].size()==1)
		if (!vis[e[i][0]]) vis[e[i][0]]=1;
		else --ans;
	printf(" %d",ans);
}
int main(){
	scanf("%d",&n);
	For(i,1,n-1){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	checkmn();
	checkmx();
}