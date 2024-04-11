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
int n,m,nd,ans1,ans2,len;
int dep[N],vis[N],flg[N];
int to[N],co[N];
vector<int> id[N];
vector<int> e[N];
void dfs(int x,int fa,int spe){
	vis[x]=2;
	//cout<<x<<' '<<fa<<endl;
	for (auto i:e[x])
		if (vis[i]!=2)
			dep[i]=dep[x]+1,dfs(i,x,spe);
		else if (i==spe) len=dep[x]+1;
}
void dfs2(int x,int fa){
	vis[x]=3;
	if (!flg[dep[x]%len]&&co[x])
		flg[dep[x]%len]=1,++ans2;
	for (auto i:e[x]) if (vis[i]!=3) dfs2(i,x);
}
void solve(int x){
	for (;!vis[x];vis[x]=1,x=to[x]);
	//cout<<x<<endl;
	dep[x]=0; dfs(x,0,x);
	//cout<<x<<' '<<len<<endl;
	For(i,0,len-1) flg[i]=0;
	ans1+=len; dfs2(x,0);
}
char s[N];
void solve(){
	nd=0;
	scanf("%d%d",&n,&m);
	For(i,1,n) id[i].resize(m+1);
	For(i,1,n) For(j,1,m) id[i][j]=++nd;
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m) co[id[i][j]]=(s[j]=='0');
	}
	For(i,1,n){
		scanf("%s",s+1);
		For(j,1,m){
			if (s[j]=='U') to[id[i][j]]=id[i-1][j];
			if (s[j]=='D') to[id[i][j]]=id[i+1][j];
			if (s[j]=='L') to[id[i][j]]=id[i][j-1];
			if (s[j]=='R') to[id[i][j]]=id[i][j+1];
		}
	}
	ans1=ans2=0;
	For(i,1,n*m) vis[i]=0;
	For(i,1,n*m) e[i].resize(0);
	For(i,1,n*m) e[to[i]].PB(i);
	For(i,1,n*m) if (!vis[i]) solve(i);
	printf("%d %d\n",ans1,ans2);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}