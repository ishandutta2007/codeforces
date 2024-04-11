#include<bits/stdc++.h>
using namespace std;
const int maxn=205;
int n,m,T,flg;
int a[maxn];
long long f[maxn+maxn][maxn];
string s;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		sort(a+1,a+1+n);
		for(int i=0;i<=n+n;i++)
			for(int j=0;j<=n;j++)
				f[i][j]=1e18;
		f[0][0]=0;
		for(int i=1;i<=n+n;i++)
			for(int j=0;j<=n;j++){
				f[i][j]=f[i-1][j];
				if(j>0)
					f[i][j]=min(f[i][j],f[i-1][j-1]+abs(a[j]-i));
			}
		printf("%lld\n",f[n+n][n]);
	}
	return 0;
}