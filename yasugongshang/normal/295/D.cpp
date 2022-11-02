#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define mo 1000000007
using namespace std;
int i,j,k,l,n,m,f[2100][2100],g[2100][2100],ans,t;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=n+1;++i){
		for(t=0,j=2;j<=m;++j)t=(t+f[i-1][j])%mo,f[i][j]=(f[i][j-1]+t)%mo;
		for(j=2;j<=m;++j)f[i][j]++;
	}
	for(i=1;i<=n;++i)
		for(j=2;j<=m;++j)ans=((long long)f[i][j]*(f[n-i+1][j]-f[n-i][j])%mo*(m-j+1)+ans)%mo;
	printf("%d\n",(ans+mo)%mo);
}