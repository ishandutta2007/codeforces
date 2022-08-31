//CF1188C
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 1111;
const int MO = 998244353;
int n,k,m,a[N],f[N][N];
int main()
{
	int i,j,o,e,t,ans=0;
	m=100005;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(o=1;o<=m/(k-1)+1;o=o+1){
		f[0][0]=1;
		t=0;
		for(i=1;i<=n;i=i+1){
			while(a[t+1]+o<=a[i]){
				t++;
			}
			f[i][0]=f[i-1][0];
			for(j=1;j<=i&&j<=k;j=j+1)
				f[i][j]=(f[i-1][j]+f[t][j-1])%MO;
		}
		ans=(ans+f[n][k])%MO;
	}
	cout<<ans;
	return 0;
}