#include<stdio.h>
#include<vector>
using namespace std;
const int maxn=300005,maxk=21;
int n,q;
int a[maxn],dep[maxn],fore[maxn][maxk];
long long f[maxn],g[maxn],h[maxn][maxk];
vector<int>v[maxn],w[maxn];
void dfs1(int x,int last){
	dep[x]=dep[last]+1,fore[x][0]=last,f[x]=a[x];
	for(int i=1;i<=20;i++)
		fore[x][i]=fore[fore[x][i-1]][i-1];
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=last)
			dfs1(v[x][i],x),f[x]+=max(0ll,f[v[x][i]]-w[x][i]*2);
}
void dfs2(int x,int last,int val){
	if(last)
		h[x][0]=f[x]+f[last]-val-max(0ll,f[x]-val*2),g[x]=max(0ll,g[last]+h[x][0]-f[x]-val);
	for(int i=1;i<=20;i++)
		h[x][i]=h[x][i-1]+h[fore[x][i-1]][i-1]-f[fore[x][i-1]];
	for(int i=0;i<v[x].size();i++)
		if(v[x][i]!=last)
			dfs2(v[x][i],x,w[x][i]);
}
long long  query(int a,int b){
	long long ext=f[a],extt=f[a]+f[b];
	if(dep[a]<dep[b])
		ext=f[b],swap(a,b);
	long long res=0;
	for(int i=20;i>=0;i--)
		if(dep[fore[a][i]]>=dep[b])
			res+=h[a][i]-f[a],a=fore[a][i];
	if(a==b)
		return res+g[a]+ext;
	for(int i=20;i>=0;i--)
		if(fore[a][i]!=fore[b][i])
			res+=(h[a][i]-f[a])+(h[b][i]-f[b]),a=fore[a][i],b=fore[b][i];
	return res+g[fore[a][0]]+extt+(h[a][0]-f[a])+(h[b][0]-f[b])-f[fore[a][0]];
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1,x,y,z;i<n;i++)
		scanf("%d%d%d",&x,&y,&z),v[x].push_back(y),w[x].push_back(z),v[y].push_back(x),w[y].push_back(z);
	dfs1(1,0),dfs2(1,0,0);
	for(int i=1,x,y;i<=q;i++)
		scanf("%d%d",&x,&y),printf("%lld\n",query(x,y));
	return 0;
}