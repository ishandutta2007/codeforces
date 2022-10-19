#include<iostream>
#include<cstdio>
#include<cmath>
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
string str[10001];
int cs[10001],cnt;
signed main()
{
    int n,m,k,x;
    n=read();
    m=read();
    k=read();
    if(k>4*m*n-2*m-2*n)
    {
        printf("NO\n");
        return 0;
    }
    if(m==1)
    {
        printf("YES\n");
        if(k<=n-1)
        {
            printf("1\n");
            printf("%d D\n",k);
        }
        else
        {
            printf("2\n");
            printf("%d D\n%d U\n",n-1,k-n+1);
        }
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if(i==1)
        {
            cs[++cnt]=m-1;
            str[cnt]="R";
            cs[++cnt]=m-1;
            str[cnt]="L";
            continue;
        }
        cs[++cnt]=1;
        str[cnt]="D";
        cs[++cnt]=m-1;
        str[cnt]="R";
        cs[++cnt]=m-1;
        str[cnt]="UDL";
        if(i==n)
        {
            cs[++cnt]=n-1;
            str[cnt]="U";
        }
    }
    for(int i=1;i<=cnt;i++)
    {
        if(k<=(int)cs[i]*str[i].length())
        {
            cs[i]=k/str[i].length();
            x=i;
            if(k%str[i].length()!=0)
            {
                if(cs[i]==0)i--;
                cs[i+1]=1;
                if(k%3==1)str[i+1]="U";
                else str[i+1]="UD";
                x=i+1;
            }
            break;
        }
        k-=cs[i]*str[i].length();
    }
    printf("YES\n");
    printf("%d\n",x);
    for(int i=1;i<=x;i++)printf("%d ",cs[i]),cout<<str[i]<<endl;
    return 0;
}