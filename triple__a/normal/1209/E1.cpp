#include<bits/stdc++.h>
using namespace std;
 
const int maxn=1<<12;
const int maxm=5007;
int n,m;
int dp[17][maxn],a[17][maxm],b[maxm],p[maxm],pre[17][maxn];
 
bool cmp(const int &u,const int &v){
	return b[u]>b[v];
}
 
void calc_pre(){
	for (int u=1;u<=min(m,n);++u){
		for (int i=0;i<(1<<n);++i){
			pre[u][i]=0;
			for (int j=0;j<n;++j){
				int sum=0;
				for (int k=0;k<n;++k){
					if ((i>>k)&1) sum+=a[(k+j)%n+1][p[u]];
				}
				pre[u][i]=max(pre[u][i],sum);
			}
//			cout<<pre[u][i]<<" ";
		}
//		cout<<endl;
	}
}
 
int calc(int u,int v){
	int ans=0;
	vector<int> tmp;
	tmp.clear();
	tmp.push_back(0);
	for (int i=0;i<n;++i){
		if ((v>>i)&1){
			int r=tmp.size();
			for (int j=0;j<r;++j){
				tmp.push_back(tmp[j]|(1<<i));
			}
		}
	}
	for (auto c:tmp){
		ans=max(dp[u-1][v^c]+pre[u][c],ans);
	}
	return ans;
}
 
int main(){
	int t;
	scanf("%d",&t);
	while (t--){
		memset(b,0,sizeof(b));
		scanf("%d%d",&n,&m);
		for (int i=1;i<=n;++i){
			for (int j=1;j<=m;++j){
				scanf("%d",&a[i][j]);
			}
		}
		for (int i=1;i<=m;++i){
			for (int j=1;j<=n;++j){
				b[i]=max(b[i],a[j][i]);
			}
			p[i]=i;
		}
		sort(p+1,p+m+1,cmp);
		calc_pre();
		memset(dp,0,sizeof(dp));
		for (int i=1;i<=min(m,n);++i){
			for (int j=1;j<(1<<n);++j){
				dp[i][j]=calc(i,j);
//				cout<<dp[i][j]<<" ";
			}
//			cout<<endl;
		}
		printf("%d\n",dp[min(m,n)][(1<<n)-1]);
	}
	return 0;
}