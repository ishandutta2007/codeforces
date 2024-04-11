#include <bits/stdc++.h>
using namespace std;

int n,a[100001],vis[100001];
vector<int> res;

int dfs(int cur) {
	vis[cur]=1;
	if(vis[a[cur]]) return 1;
	else return dfs(a[cur])+1;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",a+i);

	for(int i=1;i<=n;i++) if(!vis[i]) res.push_back(dfs(i));
	sort(res.begin(),res.end());
	
	if(res.size()==1) printf("%lld\n",1ll*n*n);
	else {
		long long ans=0;
		int v=res.back();
		res.pop_back();
		res.back()+=v;
		for(int i=0;i<res.size();i++) ans+=1ll*res[i]*res[i];
		printf("%lld\n",ans);
	}

	return 0;
}