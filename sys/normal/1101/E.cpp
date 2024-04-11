#include <bits/stdc++.h>
using namespace std;
int n,maxx,maxy;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		char ch=getchar();
		while(!(ch=='+'||ch=='?')) ch=getchar();
		if(ch=='+')
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			maxx=max(maxx,x),maxy=max(maxy,y);
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			if(x>y) swap(x,y);
			if(x>=maxx&&y>=maxy) printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}