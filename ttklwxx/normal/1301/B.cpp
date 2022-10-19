#include<iostream>
#include<cstdio>
#include<cmath>
#define int long long
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
int a[500001];
int jdz(int x)
{
	if(x>0)return x;
	return -x;
}
signed main()
{
    int t,n,ans,maxn,minn;
	bool flag;
    t=read();
    for(int sth=1;sth<=t;sth++)
    {
    	n=read();
    	for(int i=1;i<=n;i++)
    	{
    		a[i]=read();
		}
		ans=0;
		minn=1000000000000LL;
		maxn=-1000000000000LL;
		for(int i=1;i<=n-1;i++)
		{
			if(a[i]!=-1&&a[i+1]!=-1)
            {ans=max(ans,jdz(a[i]-a[i+1]));continue;}
			if(a[i]==-1&&a[i+1]==-1)continue;
			if(a[i]==-1)
			{
				maxn=max(maxn,a[i+1]);
				minn=min(minn,a[i+1]);
			}
			else
			{
				maxn=max(maxn,a[i]);
				minn=min(minn,a[i]);
			}
		}
	    cout<<max(ans,(maxn-minn+1)/2)<<" "<<(maxn+minn)/2<<endl;
	}
    return 0;
}