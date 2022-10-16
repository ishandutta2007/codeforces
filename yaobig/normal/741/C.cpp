#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 200000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

vi e[maxn+5];
int clr[maxn+5];
pii p[maxn+5];

void dfs(int now,int c)
{
	clr[now]=c;
	for(auto v: e[now]) if(clr[v]==0) dfs(v,3-c);
}

int main()
{
	int n; scanf("%d",&n);
	rep(i,1,n) e[i*2].pb(i*2-1), e[i*2-1].pb(i*2);
	rep(i,1,n)
	{
		int x,y; scanf("%d%d",&x,&y);
		e[x].pb(y);
		e[y].pb(x);
		p[i]=mp(x,y);
	}
	rep(i,1,n*2) if(clr[i]==0) dfs(i,1);
	rep(i,1,n) printf("%d %d\n",clr[p[i].FI],clr[p[i].SE]);
	return 0;
}