//CF 908E
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
const int N = 1111;
const int mod = 1e9+7;
int n,c[N][N],f[N];
char ch[N];
int m;
LL a[N];
int main()
{
	int i,j,ans=1;
	cin>>n>>m;
	for(i=0;i<=n;i=i+1){
		c[i][0]=1,c[i][i]=1;
		for(j=1;j<i;j=j+1)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%mod;
	}
	f[0]=1;
	for(i=1;i<=n;i=i+1){
		f[i]=0;
		for(j=1;j<=i;j=j+1)
			f[i]=(f[i]+(LL)c[i-1][j-1]*f[i-j]%mod)%mod;
	}
	for(i=1;i<=m;i=i+1){
		cin>>ch;
		for(j=1;j<=n;j=j+1)
			a[j]=(LL)a[j]*2+(LL)(ch[j-1]-48);
	}
	sort(a+1,a+n+1);
	j=1;
	for(i=2;i<=n+1;i=i+1){
		if(i<=n&&a[i]==a[i-1])
			j++;
		else
			ans=(LL)ans*f[j]%mod,j=1;
	}
	cout<<ans<<endl;
	return 0;
}