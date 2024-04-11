#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)
			printf("%d\n",abs(y1-y2));
		else if(y1==y2)
			printf("%d\n",abs(x1-x2));
		else
			printf("%d\n",abs(x1-x2)+abs(y1-y2)+2);
	}
	return 0;
}