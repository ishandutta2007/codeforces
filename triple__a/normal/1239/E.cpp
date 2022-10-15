#include<bits/stdc++.h>
using namespace std;

const int maxn=27;
const int maxm=50007;

int n,a[maxn<<1],sum=0;
bool vis[maxn<<1];
bool dp[maxn][maxm*maxn];
int tr[maxn][maxn*maxm];
vector<int> vec1,vec2;

void trace_back(int dep,int u){
	if (dep==0) return;
//	printf("%d %d %d\n",dep,u,tr[dep][u]);
	for (int i=3;i<=2*n;++i){
		if (!vis[i]&&a[i]==tr[dep][u]){
			vis[i]=1;
			break;
		}
	}
	trace_back(dep-1,u-tr[dep][u]);
}

int main(){
	scanf("%d",&n);
	for (int i=0;i<2;++i){
		for (int j=1;j<=n;++j){
			scanf("%d",&a[i*n+j]);
			sum+=a[i*n+j];
		}
	}
	sort(a+1,a+2*n+1);
	sum-=a[1]+a[2];
	memset(dp,0,sizeof(dp));
	dp[0][0]=1;
	for (int i=3;i<=2*n;++i){
		for (int j=min(i-3,n-1);j>-1;--j){
			for (int k=j*maxm;k>-1;--k){
				if (!dp[j+1][k+a[i]]&&dp[j][k]){
					dp[j+1][k+a[i]]=1;
					tr[j+1][k+a[i]]=a[i];
				}
			}
		}
	}
	int ans=1e9+7,idx=-1;
	for (int i=0;i<maxm*maxn;++i){
		if (dp[n-1][i]&&ans>max(sum-i,i)) ans=max(sum-i,i),idx=i;
	}
	trace_back(n-1,idx);
	vec1.push_back(a[2]);
	vec2.push_back(-a[1]);
	for (int i=3;i<=2*n;++i){
		if (vis[i]){
			vec1.push_back(a[i]);
		}
		else{
			vec2.push_back(-a[i]);
		}
	}
	sort(vec1.begin(),vec1.end());
	sort(vec2.begin(),vec2.end());
	for (auto c:vec1){
		printf("%d ",c);
	}
	printf("\n");
	for (auto c:vec2){
		printf("%d ",-c);
	}
	return 0;
}