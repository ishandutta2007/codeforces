#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,k,c[109];
ll p[109][109],f[109][109][109];

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%lld",&p[i][j]);
	memset(f,-1,sizeof(f));
	if(c[1]) f[1][c[1]][1]=0;
	else{for(int i=1;i<=m;i++) f[1][i][1]=p[1][i];}
	for(int i=2;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i-1]&&c[i-1]!=j) continue;
			for(int d=1;d<=min(i-1,k);d++){
				if(f[i-1][j][d]==-1) continue;
				if(c[i]){
					int t=d;if(c[i]!=j) t++;
					if(f[i][c[i]][t]==-1||f[i][c[i]][t]>f[i-1][j][d])
						f[i][c[i]][t]=f[i-1][j][d];
				}
				else{
					for(int col=1;col<=m;col++){
						int t=d;if(col!=j) t++;
						if(f[i][col][t]==-1||f[i][col][t]>f[i-1][j][d]+p[i][col])
							f[i][col][t]=f[i-1][j][d]+p[i][col];
					}
				}
			}
		}
	}
	ll ans=-1;
	for(int i=1;i<=m;i++)
		if(f[n][i][k]!=-1&&(ans==-1||ans>f[n][i][k]))
			ans=f[n][i][k];
	printf("%lld\n",ans);		
	return 0;
}