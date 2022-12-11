#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
bool a[12];
int main()
{
//	freopen("in.txt","r",stdin);
	int n;
	scanf("%d",&n);
	char x;
	while(scanf("%c",&x)!=EOF)
	{
		if(x=='\n') continue;
		if(x=='L')
		{
			for(int i=0;i<=9;i++)
				if(!a[i])
				{
					a[i]=true;
					break;
				}
		}
		else if(x=='R')
		{
			for(int i=9;i>=0;i--)
				if(!a[i])
				{
					a[i]=true;
					break;
				}
		}
		else a[x-'0']=false;
	}
	for(int i=0;i<=9;i++)
		printf("%d",a[i]);
	printf("\n");
	return 0;
}