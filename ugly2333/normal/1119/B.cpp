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
const int N = 333333;
int n,m,a[N],p[N];
LL t;
int main()
{
	int i,j,x;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i=i+1)
		scanf("%d",a+i);
	for(i=n;i>=1;i=i-1){
		for(j=1;j<=n;j=j+1)
			p[j]=a[j];
		sort(p+1,p+i+1);
		t=0;
		for(j=i;j>=1;j=j-2)
			t+=max(p[j],p[j-1]);
		if(t<=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}