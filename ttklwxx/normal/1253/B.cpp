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
int a[200001],b[200001],cnt,t[2000001];
bool vis[2000001];
int main()
{
    int n,sl=0;
    n=read();
    for(int i=1;i<=n;i++)a[i]=read();
    for(int i=1;i<=n;i++)
    {
    	if(a[i]<0)
    	{
    		if(t[-a[i]]==0)
    		{
    			printf("-1\n");
    			return 0;
			}
			t[-a[i]]--;
			sl--;
		}
		else
		{
			if(vis[a[i]]==true)
			{
				printf("-1\n");
				return 0;
			}
			vis[a[i]]=true;
			t[a[i]]++;
			sl++;
		}
		if(sl==0)
		{
			for(int j=b[cnt]+1;j<=i;j++)if(a[j]>0)vis[a[j]]=false;
		    b[++cnt]=i;
		}
	}
	if(sl!=0)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)printf("%d ",b[i]-b[i-1]);
	return 0;
}