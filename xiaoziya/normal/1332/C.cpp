#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,k,T,ans,mx,cnt;
string s;
int vis[maxn],tot[27];
vector<int>v[maxn];
inline void add(int x,int y){
	v[x].push_back(y),v[y].push_back(x);
}
void dfs(int x){
	vis[x]=1,cnt++,tot[s[x]-96]++;
	for(int i=0;i<v[x].size();i++)
		if(vis[v[x][i]]==0)
			dfs(v[x][i]);
}
int main(){
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%d%d",&n,&k),cin>>s;
		for(int i=0;i+k<n;i++)
			add(i,k+i);
		for(int i=0;i<n-i-1;i++)
			add(i,n-i-1);
		for(int i=0;i<n;i++)
			if(vis[i]==0){
				cnt=mx=0,dfs(i);
				for(int j=1;j<=26;j++)
					mx=max(mx,tot[j]),tot[j]=0;
				ans+=cnt-mx;
			}
		printf("%d\n",ans);
		for(int i=0;i<n;i++)
			vis[i]=0,v[i].clear();
	}
	return 0;
}