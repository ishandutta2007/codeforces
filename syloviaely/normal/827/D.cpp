#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
using namespace std;
struct bian{
	int u,v,w;
}b[210000];
int n,m;
int a[210000],f[210000],pd[210000],ans[210000],father[210000][19],w[210000][19],A[210000][19],d[210000];
map<int,int>M[210000];
vector<int>go[210000],gow[210000];
int compare(int k1,int k2){
	return b[k1].w<b[k2].w;
}
void dfs(int k1,int k2){
	father[k1][0]=k2; d[k1]=d[k2]+1;
	for (int i=0;i<go[k1].size();i++){
		int j=go[k1][i];
		if (j!=k2){
			w[j][0]=gow[k1][i]; dfs(j,k1);
		}
	}
}
pair<int,int> findfather(int k1,int k2,int k3){
	if (d[k1]<d[k2]) swap(k1,k2); int ans=0;
	for (int i=17;i>=0;i--) if ((1<<i)<=(d[k1]-d[k2])){
		A[k1][i]=min(A[k1][i],k3); ans=max(ans,w[k1][i]),k1=father[k1][i];
	}
	if (k1==k2) return make_pair(k1,ans);
	for (int i=17;i>=0;i--)
		if (father[k1][i]!=father[k2][i]){
			A[k1][i]=min(A[k1][i],k3); A[k2][i]=min(A[k2][i],k3);
			ans=max(ans,w[k1][i]); ans=max(ans,w[k2][i]);
			k1=father[k1][i]; k2=father[k2][i];
		}
	int i=0;
	A[k1][i]=min(A[k1][i],k3); A[k2][i]=min(A[k2][i],k3);
	ans=max(ans,w[k1][i]); ans=max(ans,w[k2][i]);
	k1=father[k1][i]; k2=father[k2][i];
	return make_pair(k1,ans);
}
int findfather(int k1){
	if (f[k1]==k1) return k1; return f[k1]=findfather(f[k1]);
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=m;i++){
		scanf("%d%d%d",&b[i].u,&b[i].v,&b[i].w);
		M[b[i].u][b[i].v]=M[b[i].v][b[i].u]=i;
	}
	for (int i=1;i<=m;i++) a[i]=i;
	sort(a+1,a+m+1,compare);
	for (int i=1;i<=n;i++) f[i]=i;
	for (int i=1;i<=m;i++){
		int u=findfather(b[a[i]].u),v=findfather(b[a[i]].v);
		if (u!=v){
			go[b[a[i]].u].push_back(b[a[i]].v);
			go[b[a[i]].v].push_back(b[a[i]].u);
			gow[b[a[i]].u].push_back(b[a[i]].w);
			gow[b[a[i]].v].push_back(b[a[i]].w);
			pd[a[i]]=1;
			f[u]=v;
		//	cout<<a[i]<<endl;
		}
	}
	dfs(1,0);
	memset(A,0x3f,sizeof A);
//	for (int i=1;i<=n;i++) cout<<father[i][0]<<" "; cout<<endl;
//	for (int i=1;i<=n;i++) cout<<w[i][0]<<" "; cout<<endl;
	for (int i=1;i<=17;i++)
		for (int j=1;j<=n;j++){
			father[j][i]=father[father[j][i-1]][i-1];
			w[j][i]=max(w[j][i-1],w[father[j][i-1]][i-1]);
		}
	for (int i=1;i<=m;i++)
		if (pd[a[i]]==0){
			pair<int,int>k=findfather(b[a[i]].u,b[a[i]].v,b[a[i]].w);
		//	cout<<k.first<<" "<<k.second<<" "<<b[a[i]].u<<" "<<b[a[i]].v<<endl; 
		//	cout<<a[i]<<endl;
		//	cout<<k.first<<endl;
			ans[a[i]]=k.second-1;
		}
	for (int i=16;i>=0;i--)
		for (int j=1;j<=n;j++){
			A[j][i]=min(A[j][i],A[j][i+1]);
			A[father[j][i]][i]=min(A[father[j][i]][i],A[j][i+1]);
		}
	for (int i=2;i<=n;i++){
		ans[M[i][father[i][0]]]=A[i][0]-1;
		if (ans[M[i][father[i][0]]]>1e9) ans[M[i][father[i][0]]]=-1;
	}
	for (int i=1;i<=m;i++) printf("%d ",ans[i]); printf("\n");
	return 0;
}