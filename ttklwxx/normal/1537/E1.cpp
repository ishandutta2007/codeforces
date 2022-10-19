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
char s[200005];
int n;
bool bi(int x,int y)
{
	for(int i=1;i<=x+y;i++)
	{
		if(s[(i-1)%x+1]<s[(i-1)%y+1])return true;
		if(s[(i-1)%x+1]>s[(i-1)%y+1])return false;
	}
	return false;
}
int main()
{
	int k,minn;
	n=read();
	k=read();
	minn=1;
	scanf("%s",s+1);
	for(int i=2;i<=n;i++)
	{
		if(bi(i,minn)==true)minn=i;
	}
	for(int i=1;i<=k;i++)printf("%c",s[(i-1)%minn+1]);
	return 0;
}