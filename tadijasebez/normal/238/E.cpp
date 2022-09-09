#include <bits/stdc++.h>
using namespace std;
const int N=105;
const int inf=1e9+7;
int dist[N][N],s[N],t[N],ans[N][N];
bool on[N][N];
int main(){
	int n,m,a,b;
	scanf("%i %i %i %i",&n,&m,&a,&b);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i!=j)dist[i][j]=inf;
	for(int i=1;i<=m;i++){
		int u,v;
		scanf("%i %i",&u,&v);
		dist[u][v]=1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				dist[j][k]=min(dist[j][k],dist[j][i]+dist[i][k]);
			}
		}
	}
	int k;
	scanf("%i",&k);
	for(int i=1;i<=n;i++)for(int j=1;j<=k;j++)ans[i][j]=inf;
	for(int i=1;i<=k;i++){
		scanf("%i %i",&s[i],&t[i]);
		if(dist[s[i]][t[i]]==inf)continue;
		vector<int> cnt(n+1,0);
		for(int j=1;j<=n;j++){
			if(dist[s[i]][j]+dist[j][t[i]]==dist[s[i]][t[i]]){
				cnt[dist[s[i]][j]]++;
			}
		}
		for(int j=1;j<=n;j++){
			if(dist[s[i]][j]+dist[j][t[i]]==dist[s[i]][t[i]]){
				if(cnt[dist[s[i]][j]]==1){
					on[i][j]=true;
				}
			}
		}
		ans[b][i]=1;
	}
	while(1){
		bool ch=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=k;j++)if(dist[s[j]][t[j]]!=inf){
				for(int l=1;l<=k;l++){
					if(on[l][i]){
						if(ans[i][j]>ans[i][l]+1){
							ch=1;
							ans[i][j]=ans[i][l]+1;
							//printf("1: (%i %i) %i\n",i,j,ans[i][j]);
						}
					}
				}
				int mx=0,cnt=0;
				for(int l=1;l<=n;l++){
					if(dist[s[j]][l]+dist[l][t[j]]==dist[s[j]][t[j]]){
						if(dist[s[j]][i]+1==dist[s[j]][l]&&dist[i][l]==1){
							cnt++;
							mx=max(mx,ans[l][j]);
						}
					}
				}
				if(cnt!=0){
					if(ans[i][j]>mx){
						ch=1;
						ans[i][j]=mx;
						//printf("2: (%i %i) %i\n",i,j,ans[i][j]);
					}
				}
			}
		}
		if(!ch)break;
	}
	int sol=inf;
	for(int i=1;i<=k;i++){
		if(on[i][a])sol=min(sol,ans[a][i]);
	}
	printf("%i\n",sol==inf?-1:sol);
	return 0;
}