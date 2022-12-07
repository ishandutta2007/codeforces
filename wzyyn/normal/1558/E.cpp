#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=1005;
int n,m,suc;
vector<int> e[N];
int a[N],b[N],fr[N];
long long ATK;
int vis[N];

void dfs(int x,int fa,long long ATK){
	if (suc) return;
	for (auto i:e[x])
		if (i!=fa&&a[i]<ATK){
			if (vis[i]&&vis[x]) continue;
			if (vis[i]){
				suc=1;
				for (int j=x;j;j=fr[j]) vis[j]=1;
			}
			else if (fr[i]){
				suc=1;
				for (int j=i;j;j=fr[j]) vis[j]=1;
				for (int j=x;j;j=fr[j]) vis[j]=1;
			}
			else{
				fr[i]=x;
				dfs(i,x,ATK+b[i]);
			}
			if (suc) return;
		}
}
bool check(int v){
	int rem=n-1;
	memset(vis,0,sizeof(vis));
	vis[1]=1;
	for (;;){
		bool flg=0;
		suc=0;
		long long ATK=v;
		memset(fr,0,sizeof(fr));
		for (int i=1;i<=n;i++)
			if (vis[i]) ATK+=b[i];
			else flg=1;
		if (!flg) return 1;
		for (int i=1;i<=n&&!suc;i++)
			if (vis[i]) dfs(i,0,ATK);
		if (!suc) return 0;
	}
}
void solve(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		e[i].resize(0);
	for (int i=2;i<=n;i++)
		scanf("%d",&a[i]);
	for (int i=2;i<=n;i++)
		scanf("%d",&b[i]);
	for (int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int l=1,r=1e9+5,ans=-1;
	while (l<=r){
		int mid=(l+r)/2;
		if (check(mid))
			ans=mid,r=mid-1;
		else l=mid+1;
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}