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
char sl[2][200001];
int main()
{
    int q,n,sth,nl;
    q=read();
    for(int i=1;i<=q;i++)
    {
    	n=read();
    	scanf("%s%s",sl[0]+1,sl[1]+1);
    	sth=1;
    	nl=0;
    	while(sth<=n)
    	{
    		if(sl[nl][sth]>'2')
			{
    		    nl^=1;
    		    if(sl[nl][sth]<='2')break;
			}
			sth++;
		}
		if(sth==n+1&&nl==1)printf("YES\n");
		else printf("NO\n");
	}
    return 0;
}