#include<iostream>
#include<cstdio>
#include<cstring>
#define int long long
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int c[200005];
signed main()
{
	int t,n,x,ans=0,mino,minj,heo,hej;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		for(int i=1;i<=n;i++)c[i]=read();
		mino=minj=1000000000;
		heo=hej=0; 
		ans=1121131433448687LL;
		for(int i=1;i<=n;i++)
		{
			if(i%2==0)
			{
				heo+=c[i];
				mino=min(mino,c[i]);
			}
			else
			{
				hej+=c[i];
				minj=min(minj,c[i]);
			}
			if(i==1)continue;
			ans=min(ans,heo+hej+(n-(i+1)/2)*minj+(n-i/2)*mino);
		}
		printf("%lld\n",ans);
	} 
	return 0;
}