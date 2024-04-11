#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=300005;
int n,m;
vector<int> e[N];
int ban[N],vis[N],q[N],qq[N]; 
void solve(){
	scanf("%d%d",&n,&m);
	For(i,1,n) e[i].resize(0);
	For(i,1,m){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].PB(y); e[y].PB(x);
	}
	int h=0,t=1; *qq=0;
	For(i,1,n) ban[i]=0,vis[i]=0;
	q[1]=1; qq[++*qq]=1;
	ban[1]=1; vis[1]=1;
	for (auto i:e[1]) ban[i]=1;
	while (h!=t){
		int x=q[++h];
		if (!ban[x]){
			ban[x]=1; qq[++*qq]=x;
			for (auto i:e[x]) ban[i]=1;
		}
		for (auto i:e[x])
			if (!vis[i]){
				vis[i]=1;
				q[++t]=i;
			}
	}
	if (t!=n) puts("NO");
	else{
		puts("YES");
		printf("%d\n",*qq);
		sort(qq+1,qq+*qq+1);
		For(i,1,*qq) printf("%d ",qq[i]);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}