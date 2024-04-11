#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=200050;
int l1[N],l2[N],r1[N],r2[N];
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,m,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i %i",&l1[i],&r1[i]);
	scanf("%i",&m);
	for(i=0;i<m;i++) scanf("%i %i",&l2[i],&r2[i]);
	sort(l1,l1+n);
	sort(r1,r1+n);
	sort(l2,l2+m);
	sort(r2,r2+m);
	int sol=0;
	//printf("%i %i %i %i\n",l1[n-1],r2[0],l2[m-1],r1[0]);
	sol=max(l1[n-1]-r2[0],l2[m-1]-r1[0]);
	sol=max(sol,0);
	printf("%i\n",sol);
	return 0;
}