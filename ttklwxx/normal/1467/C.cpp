#include<iostream>
#include<cstdio>
#include<algorithm>
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
int a1[300005],a2[300005],a3[300005];
signed main()
{
	int n1,n2,n3,mans=-100000000,s1=0,s2=0,s3=0;
	n1=read();
	n2=read();
	n3=read();
	for(int i=1;i<=n1;i++)a1[i]=read(),s1+=a1[i];
	for(int i=1;i<=n2;i++)a2[i]=read(),s2+=a2[i];
	for(int i=1;i<=n3;i++)a3[i]=read(),s3+=a3[i];
	sort(a1+1,a1+n1+1);
	sort(a2+1,a2+n2+1);
	sort(a3+1,a3+n3+1);
	mans=max(mans,s1+s2+s3-2*a1[1]-2*a2[1]);
	mans=max(mans,s1+s2+s3-2*a1[1]-2*a3[1]);
	mans=max(mans,s1+s2+s3-2*a3[1]-2*a2[1]);
	mans=max(mans,s1+s2+s3-2*min(min(s1,s2),s3));
	printf("%lld\n",mans);
	return 0;
}