#include<bits/stdc++.h>


using namespace std;

const int N=200005;
int n,k,v[N],vis[N];
int fa[N],dep[N],id[N];
vector<int> e[N];
void dfs(int x){
	for (auto i:e[x])
		if (i!=fa[x]){
			fa[i]=x;
			dep[i]=dep[x]+1;
			dfs(i);
		}
}
bool cmp(int x,int y){
	return dep[x]>dep[y];
}
int main(){
	scanf("%d%d",&n,&k);
	for (int i=1;i<n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(1);
	for (int i=1;i<=n;i++)
		id[i]=i;
	sort(id+1,id+n+1,cmp);
	for (int i=1;i<=n;i++){
		int x=id[i];
		for (;x&&!vis[x];x=fa[x])
			vis[x]=1,++v[i];
		//cout<<i<<' '<<v[i]<<endl;
	}
	sort(v+1,v+n+1,greater<int>());
	long long ans=-(1ll<<60);
	int s=0;
	for (int i=1;i<=k;i++){
		s+=v[i];
		int r=i,b=min(n/2,n-s);
		ans=max(ans,1ll*(n-r-b)*(r-b));
	}
	cout<<ans<<endl;
}