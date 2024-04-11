#include<bits/stdc++.h>
using namespace std;
const int N=25,S=(1<<19)+5;
int n,k,x,tmn[S],tmx[S],f[N][S],mn[N][S],mx[N][S];
signed main(){
	scanf("%d%d",&n,&k);
	for(int i=0;i<(1<<k);i++) f[0][i]=mn[0][i]=1e9,mx[0][i]=-1e9;
	for(int i=1;i<=n;i++)
		scanf("%d",&x),mn[0][x]=mx[0][x]=0;
	for(int i=1;i<=k;i++)
		for(int x=0;x<(1<<k);x++){
			int y=x^(1<<(i-1));
			mn[i][x]=min(mn[i-1][x],mn[i-1][y]+(1<<(i-1)));
			mx[i][x]=max(mx[i-1][x],mx[i-1][y]+(1<<(i-1)));
			f[i][x]=min({f[i-1][x],f[i-1][y],mn[i-1][y]+(1<<(i-1))-mx[i-1][x]});
		}
	for(int i=0;i<(1<<k);i++) printf("%d ",f[k][i]);
	return 0;
}