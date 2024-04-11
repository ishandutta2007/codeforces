#include <stdio.h>
#include <algorithm>
using namespace std;
int a[100005];
int main()
{
    int n,i,j,r=0;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i",&a[i]);
	}
	sort(a,a+n);
	i=0;
	j=n-1;
	while(j>=i)
	{
		if(a[i]+a[j]==2 && a[i+1]==1 && a[i+2]==1 && i+1!=j && i+2!=j)
		{
			i+=3;
			j--;
		}
		else if(a[i]+a[j]==2 && a[i+1]==1 && i+1!=j)
		{
			i+=2;
			j--;
		}
		else if(a[i]+a[j]==2)
		{
			i++;
			j--;
		}
		else if(a[i]+a[j]==3 && a[i+1]==1 && i+1!=j)
		{
			i+=2;
			j--;
		}
		else if(a[i]+a[j]==3)
		{
			i++;
			j--;
		}
		else if(a[i]+a[j]==4)
		{
			i++;
			j--;
		}
		else j--;
		r++;
	}
	printf("%i",r);
    return 0;
}