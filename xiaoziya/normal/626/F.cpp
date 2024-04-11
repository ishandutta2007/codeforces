#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
const int maxn=205,maxk=1005,mod=1000000007;
int n,k,ans;
int a[maxn],f[2][maxn][maxk];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	int now=0;
	f[now][0][0]=1;
	for(int i=1;i<=n;i++){
		int lst=now;
		now^=1;
		memset(f[now],0,sizeof(f[now]));
		for(int j=0;j<=i;j++)
			for(int p=0;p+1ll*(a[i]-a[i-1])*j<=k;p++)
				if(f[lst][j][p]){
					int nxtp=p+(a[i]-a[i-1])*j;
					//start
					f[now][j+1][nxtp]=(f[now][j+1][nxtp]+f[lst][j][p])%mod;
					//mid
					f[now][j][nxtp]=(f[now][j][nxtp]+1ll*j*f[lst][j][p])%mod;
					//end
					if(j>0)
						f[now][j-1][nxtp]=(f[now][j-1][nxtp]+1ll*j*f[lst][j][p])%mod;
					f[now][j][nxtp]=(f[now][j][nxtp]+f[lst][j][p])%mod;
				}
	}
	for(int i=0;i<=k;i++)
		if(f[now][0][i])
			ans=(ans+f[now][0][i])%mod;
	printf("%d\n",ans);
	return 0;
}