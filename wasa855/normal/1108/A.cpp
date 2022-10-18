#include<bits/stdc++.h>
using namespace std;
int main()
{
	int q;
	cin>>q;
	for(int i=1;i<=q;i++)
	{
		int a,b,c,d;
		scanf("%d %d %d %d",&a,&b,&c,&d);
		int x=a,y=c;
		if(x==y)
		{
			if(x!=b)
			{
				x++;
			}
			else if(y!=d)
			{
				y++;
			}
		}
		printf("%d %d\n",x,y);
	}
	return 0;
}