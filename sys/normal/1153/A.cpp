#include <bits/stdc++.h>
using namespace std;
int n,t,ans=0x3f3f3f3f,pnt; 
int main()
{
	scanf("%d%d",&n,&t);
	for(int i=1;i<=n;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		if(a>t)
		{
			if(ans>a-t)
				ans=a-t,pnt=i;
		}
		else if(((a-t)%b+b)%b<ans)
			ans=((a-t)%b+b)%b,pnt=i;
	}
	printf("%d",pnt);
	return 0;
}