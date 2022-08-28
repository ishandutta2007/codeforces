//CF 569D
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
const int mod = 1e9+7;
int c[4444][4444],f[4444];
int main()
{
	int n,i,j;
	cin>>n;
	n++;
	c[0][0]=1;
	for(i=1;i<=n;i=i+1){
		c[i][0]=1;
		for(j=1;j<i;j=j+1)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%mod;
		c[i][i]=1;
	}
	f[0]=1;
	for(i=1;i<=n;i=i+1){
		f[i]=0;
		for(j=1;j<=i;j=j+1){
			f[i]=((LL)f[i-j]*c[i-1][j-1]%mod+f[i])%mod;
		}
	}
	cout<<(f[n]-f[n-1]+mod)%mod<<endl;
	return 0;
}