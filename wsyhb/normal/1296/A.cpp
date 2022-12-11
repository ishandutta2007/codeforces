#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		int s=0;
		bool f1=false,f2=false;
		while(n--)
		{
			int x;
			scanf("%d",&x);
			s+=x;
			if(x&1) f1=true;
			else f2=true;
		}
		if(s&1) printf("YES\n");
		else
		{
			if(f1&&f2) printf("YES\n");
			else printf("NO\n");
		}
	}
	return 0;
}