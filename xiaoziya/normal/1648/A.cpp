#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
int n,m;
int cnt[maxn];
long long ans;
long long sum[maxn];
vector<int>v[maxn];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		v[i].resize(m);
		for(int j=0;j<m;j++)
			scanf("%d",&v[i][j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<m;j++)
			ans+=1ll*cnt[v[i][j]]*i+sum[v[i][j]];
		for(int j=0;j<m;j++)
			cnt[v[i][j]]++,sum[v[i][j]]-=i;
	}
	memset(cnt,0,sizeof(cnt)),memset(sum,0,sizeof(sum));
	for(int j=0;j<m;j++){
		for(int i=1;i<=n;i++)
			ans+=1ll*cnt[v[i][j]]*j+sum[v[i][j]];
		for(int i=1;i<=n;i++)
			cnt[v[i][j]]++,sum[v[i][j]]-=j;
	}
	printf("%lld\n",ans);
	return 0;
}