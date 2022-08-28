//CF1081C
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
const int N = 2222;
const int MO = 998244353;
int n,m,k,c[N][N];
int main()
{
	int i,j,s;
	cin>>n>>m>>k;
	for(i=0;i<=n;i=i+1){
		c[i][0]=1;
		for(j=1;j<=i;j=j+1){
			c[i][j]=c[i-1][j-1]+c[i-1][j];
			c[i][j]%=MO;
		}
	}
	s=(LL)c[n-1][k]*m%MO;
	for(i=1;i<=k;i=i+1)
		s=(LL)s*(m-1)%MO;
	cout<<s;
	return 0;
}