#include<bits/stdc++.h>
using namespace std;
const int N=105;
int a[N];
int main()
{
	int n,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=2;i<n;i++)
	{
		if(a[i]==0)
		{
			if(a[i-1]&&a[i+1])
			{
				a[i+1]=0;
				sum++;
			}
		}
	}
	printf("%d\n",sum);
	return 0;
}