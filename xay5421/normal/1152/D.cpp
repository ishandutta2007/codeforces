#include<cstdio>
#define int long long
const int N=2005,p=1000000007;
int n,f[N][N][2];
signed main(){
	scanf("%I64d",&n);
	for(int j=n*2-1;~j;--j){
		for(int i=0;i<=j&&i<=n*2-j;++i){
			if(!i)f[j][i][1]=(f[j+1][i+1][0]+1)%p;else f[j][i][1]=(f[j+1][i-1][0]+f[j+1][i+1][0]+1)%p;
			if(!i)f[j][i][0]=f[j+1][i+1][1];else f[j][i][0]=(f[j+1][i+1][1]+f[j+1][i-1][1])%p;
		}
	}
	printf("%I64d\n",f[0][0][0]);
	return 0;
}