#include<bits/stdc++.h>
using namespace std;
const int N=1003;
int n,a[N],vis[1000005],pr[N];
vector<int>g[1000005],val;
bool check(int x){
	if(vis[x])return 0;
	vis[x]=1;
	for(auto y:g[x]){
		if(pr[y]==-1||check(pr[y])){
			pr[y]=x;
			return 1;
		}
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			val.push_back(a[i]*j);
		}
	}
	sort(val.begin(),val.end());
	val.erase(unique(val.begin(),val.end()),val.end());
	int v=val.size();
	long long ans=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=n;j++){
			int k=lower_bound(val.begin(),val.end(),a[i]*j)-val.begin();
			g[k].push_back(i);
		}
	}
	for(int i=0;i<n;i++)pr[i]=-1;
	for(int i=0;i<v;i++){
		if(check(i)){
			ans+=val[i];
			for(int j=0;j<v;j++)vis[j]=0;
		}
	}
	printf("%lld",ans);
}