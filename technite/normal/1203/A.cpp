#include<bits/stdc++.h>
using namespace std;
int Q,n,a,x,c,b;
int main()
{
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&n,&a);
		x=a;c=0;
		for(int j=1;j<n;j++)
		{
			scanf("%d",&b);
			if(abs(a-b)>1)c++;
			a=b;
		}
		if(abs(x-a)>1)c++;
		if(c>1)puts("NO");else puts("YES");
	}
}