#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,T,ans;
int l[maxn],r[maxn];
vector<int>v[maxn];
long long dfs(int x){
	long long sum=0;
	for(int i=0;i<v[x].size();i++)
		sum+=dfs(v[x][i]);
	if(sum<l[x]){
		ans++;
		return r[x];
	}
	return min(0ll+r[x],sum);
}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n),ans=0;
		for(int i=2,x;i<=n;i++)
			scanf("%d",&x),v[x].push_back(i);
		for(int i=1;i<=n;i++)
			scanf("%d%d",&l[i],&r[i]);
		dfs(1);
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			v[i].clear();
	}
	return 0;
}