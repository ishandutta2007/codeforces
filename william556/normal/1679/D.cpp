#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
int a[N];
long long k;
int now,t;
int vis[N],f[N];
bool flag=0;
vector<int> e[N];
bool ins[N];
void dfs(int x){
	vis[x]=1,ins[x]=1;
	for(int y:e[x]){
		if(a[y]>now)continue;
		if(ins[y])flag=1;
		else {
			if(!vis[y])dfs(y);
			f[x]=max(f[x],f[y]+1);
		}
	}
	ins[x]=0;
}
bool check(int mid){
	now=mid;flag=0;
	for(int i=1;i<=n;i++)vis[i]=f[i]=0;
	for(int i=1;i<=n;i++){
		if(vis[i]||a[i]>now)continue;
		t++;
		dfs(i);
	}
	if(flag)return 1;
	for(int i=1;i<=n;i++)if(f[i]>=k-1)return 1;
	return 0;
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	int mn=2e9;
	for(int i=1;i<=n;i++){
		scanf("%d",a+i);
		mn=min(mn,a[i]);
	}
	if(k==1)return cout<<mn,0;
	for(int i=1;i<=m;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
	}
	int l=0,r=1e9,mid,ans=-1;
	while(l<=r){
		mid=l+r>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;	
	}
	cout<<ans;
	return 0;
}