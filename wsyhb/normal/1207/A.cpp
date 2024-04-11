#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int b,p,f,h,c,ans=0;
		scanf("%d%d%d%d%d",&b,&p,&f,&h,&c);
		b/=2;
		if(h<c) swap(p,f),swap(h,c);
		ans+=h*min(b,p);
		b-=min(b,p);
		if(b>0) ans+=c*min(b,f);
		printf("%d\n",ans);
	}
	return 0;
}