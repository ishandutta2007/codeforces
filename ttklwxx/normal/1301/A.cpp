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
char a[1001],b[1001],c[1001];
int main()
{
    int t,n;
	bool flag;
    t=read();
    for(int i=1;i<=t;i++)
    {
    	scanf("%s%s%s",a+1,b+1,c+1);
    	n=strlen(a+1);
    	flag=false;
    	for(int j=1;j<=n;j++) 
		{
    		if(c[j]!=a[j]&&c[j]!=b[j])
    		{
    			printf("NO\n");
    			flag=true;
    			break;
			}
    	} 
    	if(flag==false)printf("YES\n");
	}
    return 0;
}