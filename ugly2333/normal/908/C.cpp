//CF 908C
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
const int N = 1111;
int n,r,x[N];
DB y[N];
int main()
{
	int i,j,xx;
	DB yy;
	cin>>n>>r;
	for(i=1;i<=n;i=i+1){
		cin>>x[i];
		y[i]=(DB)r;
		for(j=1;j<i;j=j+1){
			xx=x[i]-x[j];
			if(xx>r+r||xx<-r-r)
				continue;
			yy=(DB)sqrt((DB)r*r*4-(DB)xx*xx);
			if(yy+y[j]>y[i])
				y[i]=yy+y[j];
		}
		printf("%.9f ",y[i]);
	}
	return 0;
}