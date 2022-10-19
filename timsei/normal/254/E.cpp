using namespace std;
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 1001
#define LL long long
int dp[N][N],pre[N][N];
vector<int>path[N][N];
int a[N];
struct fri{
	int id,fo;
	friend bool operator < (fri xx,fri yy) {
		return xx.fo<yy.fo;
	}
}ind;
vector<fri>F[N];
vector<int>fall;
int l,r,n,m,k,v;
bool vis[N][N];
void print(int i,int no) {
	if(i==0) return;
	print(i-1,pre[i][no]);
	cout<<path[i][no].size()<<" ";
	for(int j=0;j<path[i][no].size();j++) cout<<path[i][no][j]<<" ";
	puts("");
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin>>n;cin>>v;for(int i=1;i<=n;i++) cin>>a[i];
	cin>>m;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&l,&r,&k);
		ind.fo=k;ind.id=i;
		for(int j=l;j<=r;j++) F[j].push_back(ind);
	}
	memset(dp,-1,sizeof(dp));
	dp[0][0]=0;vis[0][0]=1;
	for(int i=1;i<=n;i++) sort(F[i].begin(),F[i].end());
	for(int i=0;i<=n-1;i++) {
		for(int j=0;j<=a[i];j++) {
			if(vis[i][j]) {
				fall.clear();
				int leo=j,now=a[i+1];
				if(leo>=v)leo-=v;else now=now+leo-v,leo=0;
				if(dp[i+1][now]<dp[i][j]) {
					pre[i+1][now]=j;dp[i+1][now]=dp[i][j];vis[i+1][now]=1;
					path[i+1][now].clear();
				}
				int hh=0;
				for(int k=0,len=F[i+1].size();k<len;k++) {
					fri q=F[i+1][k];int id=q.id;int fo=q.fo;
					if(leo>=fo) leo-=fo;else now=now+leo-fo,leo=0;
					if(now<0) break;hh++;fall.push_back(id);
					if(dp[i+1][now]<dp[i][j]+hh) {
						pre[i+1][now]=j;dp[i+1][now]=dp[i][j]+hh;vis[i+1][now]=1;
						path[i+1][now]=fall;
					}
				}
			}
		}
	}
	int no=-1,ans=-1;
	for(int i=0;i<=a[n];i++) {
		if(dp[n][i]>ans) {
			ans=dp[n][i];no=i;
		}
	}
	cout<<ans<<endl;
	print(n,no);
}