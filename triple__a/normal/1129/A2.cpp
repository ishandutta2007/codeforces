#include<bits/stdc++.h>
using namespace std;

const int maxn=5007;

int n,m,ans[maxn];
vector<int> a[maxn];
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	while(m--){
		int u,v;
		cin>>u>>v;
		a[u].push_back(v);
	}
	for (int i=1;i<=n;++i){
		sort(a[i].begin(),a[i].end());
	}
	
	for (int i=1;i<=n;++i){
		ans[i]=0;
		for (int j=1;j<=n;++j){
			if (a[j].size()){
				int pt=upper_bound(a[j].begin(),a[j].end(),j)-a[j].begin();
				if (pt!=a[j].size()){
					ans[i]=max(ans[i],(int)(((j-i)%n+n)%n+a[j][pt]-j+(a[j].size()-1)*n));
				}
				else{
					ans[i]=max(ans[i],(int)(((j-i)%n+n)%n+((a[j][0]-j)%n+n)%n+(a[j].size()-1)*n));
				}
			}
		}
	}
	for (int i=1;i<=n;++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}