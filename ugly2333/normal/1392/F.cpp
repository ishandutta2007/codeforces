//CF1392F
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
const int N = 1e6+16;
int n;
LL a[N],s;
int main()
{
	int i;
	scanf("%d",&n);
	for(i=1;i<=n;i=i+1)
		scanf("%lld",a+i),s+=a[i];
	for(i=1;i<=n;i=i+1)
		a[i]=i-1,s-=i-1;
	for(i=1;i<=n;i=i+1)
		a[i]+=s/n;
	s%=n;
	for(i=1;i<=s;i=i+1)
		a[i]++;
	for(i=1;i<=n;i=i+1)
		printf("%lld ",a[i]);
	return 0;
}