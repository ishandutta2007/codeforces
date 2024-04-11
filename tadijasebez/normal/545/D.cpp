#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100050];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=0;i<n;i++) scanf("%i",&a[i]);
	int mass=0;
	sort(a,a+n);
	int ans=0;
	for(i=0;i<n;i++)
	{
		if(mass>a[i]) ans++;
		else mass+=a[i];
	}
	printf("%i\n",n-ans);
	return 0;
}