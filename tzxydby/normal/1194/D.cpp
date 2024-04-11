#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,k;
		scanf("%d%d",&n,&k);
		if(n==0)
		{
			puts("Bob");
			continue;
		}
		if(k==3)
		{
			if(n%4==0)
				puts("Bob");
			else
				puts("Alice");
			continue; 
		}
		if(k%3)
		{
			if(n%3)
				puts("Alice");
			else
				puts("Bob");
		}	
		else
		{
			int s=k/3-1;
			int x=s*3+4;
			int r=n%x;
			if((r%3==0||r==0)&&(r+1)%x!=0)
				puts("Bob");
			else
				puts("Alice");
		}
	} 
	return 0;
}