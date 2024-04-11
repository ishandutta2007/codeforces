#include<iostream>
#include<cstdio>
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
void write(int x)
{
	if(x<1000)putchar('0');
	if(x<100)putchar('0');
	if(x<10)putchar('0');
	printf("%d\n",x);
}
int sl[10001],ys[10001];
int main()
{
	int t,n,x,ans;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		ans=0;
		for(int j=1;j<=n;j++)ys[j]=read(),sl[ys[j]]++;
		for(int j=1;j<=n;j++)
		{
			if(sl[ys[j]]==1)continue;
			x=ys[j]/10*10;
			for(int k=0;k<=9;k++)if(sl[x+k]==0){
				sl[ys[j]]--;
				sl[x+k]++;
				ys[j]=x+k;
				ans++;
				break;
			}
		}
		for(int j=0;j<=9999;j++)sl[j]=0;
		printf("%d\n",ans);
		for(int j=1;j<=n;j++)write(ys[j]);
	}
	return 0;
}