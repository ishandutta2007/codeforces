#include<bits/stdc++.h>
using namespace std;
const int inf=2e9;
int n,s,c3,c4,c5,ans=inf,p3,p4,p5;
int main()
{
	scanf("%d%d",&n,&s);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if(x==3) c3++;
		if(x==4) c4++;
		if(x==5) c5++;
	}
	for(int v3=s/n;v3>=0;v3--)
	{
		for(int v4=(s-c3*v3)/(c4+c5);v4>=v3;v4--)
		{
			int v5=(s-c3*v3-c4*v4)/c5;
			int z=c5*v5-c4*v4;
			if(z>ans) break;
			if(c3*v3+c4*v4+c5*v5==s)
			{
				int w=abs(c3*v3-c4*v4)+abs(z);
				if(w<ans) ans=w,p3=v3,p4=v4,p5=v5;
			}
		}
	}
	if(ans==inf)
		puts("-1");
	else
		printf("%d %d %d\n",p3,p4,p5);
	return 0;
}