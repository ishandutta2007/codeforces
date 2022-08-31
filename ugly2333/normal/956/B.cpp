//
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
const int N = 3e5+35;
int n,u,a[N];
int main()
{
	int i,j,f=0;
	DB ans=0;
	scanf("%d%d",&n,&u);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=1,j=1;i<n;i=i+1){
		while(j<n&&a[j+1]-a[i]<=u){
			j++;
		}
		if(i+1<j){
			f=1;
			ans=max(ans,(DB)(a[j]-a[i+1])/(a[j]-a[i]));
		}
	}
	if(!f)
		printf("-1");
	else
		printf("%.9lf",ans);
	return 0;
}