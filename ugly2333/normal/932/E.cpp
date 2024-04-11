//CF 932E
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 5005;
const int mod = 1e9+7;
int n=5000,k,nn,c[N][N],f[N][N];
int fpow(int x,int y){
	if(!y)
		return 1;
	LL z=fpow(x,y>>1);
	z=z*z%mod;
	if(y&1)
		z=z*x%mod;
	return z;
}
int getf(int n,int k){
	if(f[nn-n][k])
		return f[nn-n][k];
	if(n==1)
		return 1;
	if(k==0)
		return fpow(2,n)-1;
	return f[nn-n][k]=(LL)n*(getf(n,k-1)-getf(n-1,k-1)+mod)%mod;
}
int main()
{
	int i,j;
	for(i=0;i<=n;i=i+1){
		c[i][0]=1;
		for(j=1;j<=i;j=j+1)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
	cin>>nn>>k;
	cout<<getf(nn,k);
	return 0;
}