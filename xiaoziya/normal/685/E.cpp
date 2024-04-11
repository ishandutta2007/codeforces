#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int maxn=1005,maxm=200005,maxq=200005;
int n,m,q;
int x[maxm],y[maxm],R[maxq],S[maxq],T[maxq],ans[maxq],dis[maxn][maxn];
vector<int>v[maxm];
int main(){
	memset(dis,0x3f,sizeof(dis));
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
		scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<=q;i++){
		int l;
		scanf("%d%d%d%d",&l,&R[i],&S[i],&T[i]);
		v[l].push_back(i);
	}
	for(int i=m;i>=1;i--){
		dis[x[i]][y[i]]=dis[y[i]][x[i]]=i;
		for(int j=1;j<=n;j++){
			dis[x[i]][j]=min(dis[x[i]][j],dis[y[i]][j]);
			dis[y[i]][j]=min(dis[y[i]][j],dis[x[i]][j]);
		}
		for(int j=0;j<v[i].size();j++){
			int k=v[i][j];
			ans[k]=(dis[S[k]][T[k]]<=R[k]);
		}
	}
	for(int i=1;i<=q;i++)
		puts(ans[i]==0? "No":"Yes");
	return 0;
}