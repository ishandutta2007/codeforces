#include <stdio.h>
#include <algorithm>
using namespace std;
const int N=200050;
int a[N];
bool done[N];
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,m,k,i;
	scanf("%i %i %i",&n,&m,&k);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	sort(a+1,a+1+n);
	int sol=0,j=1;
	for(i=k;i<=n;i++)
	{
		while(j<n && done[j]) j++;
		if(a[i]-a[j]+1<=m)
		{
			done[i]=1;
			sol++;
		}
		else j++;
	}
	/*int ans=0;
	j=n;
	for(i=n-k+1;i;i--)
	{
		if(a[j]-a[i]+1<=m)
		{
			ans++;
		}
		else j--;
	}*/
	printf("%i\n",sol);
	return 0;
}