//CF1446B
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
const int N = 5555;
int n,m,f[N][N];
char a[N],b[N];
int main()
{
	int i,j,ans;
	scanf("%d%d%s%s",&n,&m,a+1,b+1);
	ans=0;
	for(i=1;i<=n;i=i+1){
		for(j=1;j<=m;j=j+1){
			f[i][j]=4*(a[i]==b[j])-2;
			f[i][j]=max(f[i][j],f[i-1][j]-1);
			f[i][j]=max(f[i][j],f[i][j-1]-1);
			f[i][j]=max(f[i][j],f[i-1][j-1]+4*(a[i]==b[j])-2);
			//cout<<i<<j<<f[i][j]<<endl;
			ans=max(ans,f[i][j]);
		}
	}
	cout<<ans;
	return 0;
}