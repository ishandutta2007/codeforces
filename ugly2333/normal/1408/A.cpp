//CF1408A
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
const int N = 111;
int n,a[N],b[N][3];
int main()
{
	int T,i,j,x,y,z;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(j=0;j<3;j=j+1)
			for(i=1;i<=n;i=i+1)
				scanf("%d",b[i]+j);
		for(i=1;i<=n;i=i+1){
			x=b[i][0],y=b[i][1];
			if(i==1)
				a[i]=x;
			else{
				if(a[i-1]==x)
					a[i]=y;
				else
					a[i]=x;
			}
		}
		if(a[1]==a[n]){
			for(j=0;j<3;j=j+1)
				if(a[1]!=b[n][j]&&a[n-1]!=b[n][j])
					a[n]=b[n][j];
		}
		for(i=1;i<=n;i=i+1)
			printf("%d ",a[i]);
		printf("\n");
	}
	return 0;
}