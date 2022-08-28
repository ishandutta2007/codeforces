//CF 932C
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
int main()
{
	int n,a,b;
	int i,j;
	cin>>n>>a>>b;
	for(i=0;i*a<=n;i=i+1){
		if((n-i*a)%b)
			continue;
		for(j=1;j<=i*a;j=j+1){
			if(j%a)
				printf("%d ",j+1);
			else
				printf("%d ",j-a+1);
		}
		a=i*a;
		i=(n-a)/b;
		for(j=1;j<=i*b;j=j+1){
			if(j%b)
				printf("%d ",a+j+1);
			else
				printf("%d ",a+j-b+1);
		}
		return 0;
	}
	printf("-1");
	return 0;
}