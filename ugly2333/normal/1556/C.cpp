//CF1556C
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
int n;
LL a[N];
int main()
{
	int i,j;
	LL s=0,x,y;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		scanf("%lld",a+i);
	for(i=1;i<=n;i+=2){
		x=0,y=0;
		if(i<n)
			s--;
		for(j=i+1;j<=n;j+=2){
			s+=max((LL)0,min(a[i]+y+1,a[j]-x+y+1));
			x-=a[j];
			y=min(y,x);
			x+=a[j+1];
		}
	}
	printf("%lld\n",s);
	return 0;
}