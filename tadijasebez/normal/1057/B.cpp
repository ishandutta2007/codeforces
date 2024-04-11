#include <bits/stdc++.h>
using namespace std;
const int N=5050;
int a[N];
int main()
{
	int n,i,j,sol=0;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),a[i]+=a[i-1];
	for(i=1;i<=n;i++) for(j=i;j<=n;j++) if(a[j]-a[i-1]>(j-i+1)*100) sol=max(sol,j-i+1);
	printf("%i\n",sol);
	return 0;
}