#include<iostream>
#include<cstdio>
#include<cstring>
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
int main()
{
	scanf("%s",s+1);
	int n;
	n=strlen(s+1);
	printf("3\n");
	printf("R %d\n",n-1);
	printf("L %d\n",n);
	printf("L %d\n",2);
	return 0;
}