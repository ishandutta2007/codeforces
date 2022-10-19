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
int main()
{
	int t,s1,s2,s3,s4;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		s1=read();
		s2=read();
		s3=read();
		s4=read();
		if(min(s1,s2)>max(s3,s4))printf("NO\n");
		else if(min(s3,s4)>max(s1,s2))printf("NO\n");
		else printf("YES\n");
	} 
	return 0;
}