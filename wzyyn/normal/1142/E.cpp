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
int vis[N],in[N];
vector<int> e[N],vec[N],q;
int n,m,ins[N];
void dfs(int x){
	vis[x]=ins[x]=1;
	for (auto i:vec[x]){
		if (!ins[i]) e[x].PB(i),++in[i];
		if (!vis[i]) dfs(i);
	}
	ins[x]=0;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		vec[x].PB(y);
	}
	For(i,1,n)
		if (!vis[i])
			dfs(i);
	For(i,1,n)
		if (!in[i])
			q.PB(i);
	while (q.size()!=1){
		int x=q.back(); q.pop_back();
		int y=q.back(); q.pop_back();
		printf("? %d %d\n",x,y);
		fflush(stdout);
		int res;
		scanf("%d",&res);
		if (res==0) swap(x,y);
		q.PB(x);
		for (auto i:e[y])
			if (!--in[i])
				q.PB(i);
	}
	printf("! %d",q[0]);
}