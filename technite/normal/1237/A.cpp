#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,y=1;
	scanf("%d",&n);
	
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&x);
		if(x%2==0)printf("%d\n",x/2);
		else
		{
			printf("%d\n",(x+y)/2);
			y=-y;
		}
	}
	return 0; 
}