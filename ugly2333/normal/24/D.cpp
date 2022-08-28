//CF 24D
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
typedef double DB;
const int N = 1005;
int n,m,x,y;
double a[N],t[N][N],d;
int main()
{
	int i,j;
	cin>>n>>m>>x>>y;
	n-=x;
	if(m==1){
		printf("%.9lf",2.0*n);
		return 0;
	}
	for(i=1;i<=m;i=i+1)
		a[i]=0.0;
	while(n--){
		for(i=1;i<m;i=i+1){
			t[i][i]=3.0;
			t[i][i+1]=-1.0;
			t[i+1][i]=-1.0;
		}
		t[1][1]=2.0;
		t[m][m]=2.0;
		for(i=1;i<=m;i=i+1)
			a[i]+=t[i][i]+1.0;
		for(i=1;i<=m;i=i+1){
			if(i==m)
				break;
			a[i+1]+=a[i]/t[i][i];
			for(j=i;j<=i+2&&j<=m;j=j+1)
				t[i+1][j]+=t[i][j]/t[i][i];
		}
		for(i=m;i>=1;i=i-1){
			a[i]/=t[i][i];
			if(i==1)
				break;
			a[i-1]-=a[i]*t[i-1][i];
		}
	}
	printf("%.9lf",a[y]);
	return 0;
}