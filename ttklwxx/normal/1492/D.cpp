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
char sa[200005];
int main()
{
	int a,b,k,len;
	a=read();
	b=read();
	k=read();
	for(int i=1;i<=b;i++)sa[i]='1';
	for(int i=b+1;i<=a+b;i++)sa[i]='0';
	len=a+b;
	while((len-k>=1)&&(sa[len]=='1'||sa[len-k]=='0'))len--;
	if(len-k<=1&&k>=1)printf("No\n");
	else
	{
		printf("Yes\n");
		printf("%s\n",sa+1);
		swap(sa[len-k],sa[len]);
		printf("%s\n",sa+1);
	}
	return 0;
}