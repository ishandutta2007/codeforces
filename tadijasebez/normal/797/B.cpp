#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[100000];
vector<int> odd;
int main()
{
	int n,i,sol=0;
	scanf("%i",&n);
	for(i=0;i<n;i++)
	{
		scanf("%i",&a[i]);
		if(a[i]%2==0)
		{
			if(a[i]>0) sol+=a[i];
		}
		else
		{
			odd.push_back(-a[i]);
		}
	}
	sort(odd.begin(),odd.end());
	sol-=odd[0];
	for(i=1;i<odd.size()-1;i+=2)
	{
		if(-(odd[i]+odd[i+1])>0) sol-=odd[i]+odd[i+1];
		else break;
	}
	printf("%i",sol);
	return 0;
}