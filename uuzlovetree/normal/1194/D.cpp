#include<bits/stdc++.h>
using namespace std;
int T,n,k;
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&k);
		if(k%3)
		{
			if(n%3)puts("Alice");else puts("Bob");
		}
		else
		{
			int t=n%(k+1);
			if(t==k)puts("Alice");
			else
			{
				if(t%3)puts("Alice");else puts("Bob");
			}
		}
	}
}