#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
int Min=1e9+7,pre,sol=1e9+7,a[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),Min=min(Min,a[i]);
	for(i=1;i<=n;i++)
	{
		if(pre && a[i]==Min)
		{
			sol=min(i-pre,sol);
		}
		if(a[i]==Min) pre=i;
	}
	printf("%i\n",sol);
	return 0;
}