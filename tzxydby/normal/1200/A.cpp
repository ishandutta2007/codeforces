#include<bits/stdc++.h>
using namespace std;
int a[15];
int main()
{
	int n;
	scanf("%d\n",&n);
	for(int i=1;i<=n;i++)
	{
		char c;
		scanf("%c",&c);
		if(c=='L')
		{
			for(int j=1;j<=10;j++)
			{
				if(!a[j])
				{
					a[j]=1;
					break;
				}
			}
		}
		else if(c=='R')
		{
			for(int j=10;j>=1;j--)
			{
				if(!a[j])
				{
					a[j]=1;
					break;
				}
			}
		}
		else
			a[c-'0'+1]=0;
	}
	for(int i=1;i<=10;i++)
		printf("%d",a[i]);
	return 0;
}