//CF1119B
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
const int N = 555;
int n,m,a[N][N],b[N][N];
int main()
{
	int i,j,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			scanf("%d",a[i]+j);
	for(i=1;i<=n;i=i+1)
		for(j=1;j<=m;j=j+1)
			scanf("%d",b[i]+j);
	for(i=1;i<=n;i=i+1){
		x=0;
		for(j=1;j<=m;j=j+1)
			if(a[i][j]!=b[i][j])
				x^=1;
		if(x){
			cout<<"No";
			return 0;
		}
	}
	for(i=1;i<=m;i=i+1){
		x=0;
		for(j=1;j<=n;j=j+1)
			if(a[j][i]!=b[j][i])
				x^=1;
		if(x){
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}