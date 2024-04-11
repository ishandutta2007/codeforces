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
char a[10001],b[10001];
bool cza[27],czb[27];
int main()
{
    int n,q;
    bool flag;
	q=read();
	for(int i=1;i<=q;i++)
	{
		for(int j=0;j<=26;j++)cza[j]=0,czb[j]=0;
		scanf("%s%s",a+1,b+1);
		for(int j=1;a[j]!=0;j++)cza[a[j]-'a']=1;
		for(int j=1;b[j]!=0;j++)czb[b[j]-'a']=1;
		flag=false;
		for(int j=0;j<=26;j++)if(cza[j]==1&&czb[j]==1)
		{
			printf("YES\n");
			flag=true;
			break;
		}
		if(flag==false)printf("NO\n");
	}
    return 0;
}