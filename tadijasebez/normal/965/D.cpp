#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int N=100050;
int a[N],b[N];
const int inf=1e9+7;
int min(int a, int b){ return a>b?b:a;}
int Get(int l, int r){ return b[r]-b[l-1];}
int main()
{
	int n,l,i;
	scanf("%i %i",&n,&l);
	for(i=1;i<n;i++) scanf("%i",&a[i]),b[i]=b[i-1]+a[i];
	int sol=inf;
	for(i=1;i<n-l+1;i++) sol=min(sol,Get(i,i+l-1));//,printf("%i %i\n",i,i+l-1);
	printf("%i\n",sol);
	return 0;
}