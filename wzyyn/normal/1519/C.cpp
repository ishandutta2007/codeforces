#include<bits/stdc++.h>
using namespace std;

const int N=500005;
int n;
int u[N],s[N];
long long ans[N],sum[N];
vector<int> v[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&u[i]);
	for (int i=1;i<=n;i++)
		scanf("%d",&s[i]);
	for (int i=1;i<=n;i++){
		v[i].resize(0);
		ans[i]=0;
	}
	for (int i=1;i<=n;i++)
		v[u[i]].push_back(s[i]);
	for (int i=1;i<=n;i++){
		sort(v[i].begin(),v[i].end());
		reverse(v[i].begin(),v[i].end());
		for (int j=1;j<=v[i].size();j++)
			sum[j]=sum[j-1]+v[i][j-1];
		for (int j=1;j<=v[i].size();j++)
			ans[j]+=sum[v[i].size()/j*j]; 
	}
	for (int i=1;i<=n;i++)
		printf("%lld ",ans[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}