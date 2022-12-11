#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int s,ans=0;
		scanf("%d",&s);
		while(s>=10)
		{
			int now=s/10;
			s%=10;
			ans+=now*10;
			s+=now;
		}
		printf("%d\n",ans+s);
	}
	return 0;
}