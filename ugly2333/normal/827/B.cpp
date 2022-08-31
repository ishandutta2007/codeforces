// CF 827B
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
int main()
{
	int n,k,i;
	scanf("%d%d",&n,&k);
	n--;
	i=n/k;
	i*=2;
	if(n%k>1)
		i+=2;
	else
		i+=n%k;
	printf("%d\n",i);
	n++;
	for(i=1;i<=k;i=i+1)
		printf("%d %d\n",i,n);
	for(i=k+1;i<n;i=i+1)
		printf("%d %d\n",i,i-k);
	return 0;
}