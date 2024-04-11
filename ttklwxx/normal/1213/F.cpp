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
int p[200005],q[200005],sl=0;
int tp[200005],tq[200005],sth[200005];
char a[200005];
int main()
{
	int n,x,k,sa=0,sb=0,ans=0;
	n=read();
	k=read();
	for(int i=1;i<=n;i++)p[i]=read();
    for(int i=1;i<=n;i++)q[i]=read();
    for(int i=1;i<=n;i++)
    {
    	if(tp[q[i]]==1)tp[q[i]]=0,sa--;
    	else tq[q[i]]=1,sb++;
    	if(tq[p[i]]==1)tq[p[i]]=0,sb--;
    	else tp[p[i]]=1,sa++;
    	if(sa==0&&sb==0)ans++,sth[ans]=i;
    }
    if(ans<k)
    {
    	printf("NO\n");
    	return 0;
    }
    for(int i=1;i<=ans;i++)
    {
    	for(int j=sth[i-1]+1;j<=sth[i];j++)
    	{
    		a[p[j]]=min((int)'z','a'+i-1);
    	}
    }
    printf("YES\n%s\n",a+1);
    return 0;
}