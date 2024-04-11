#include<iostream>
#include<cstdio>
#include<set>
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
int a[200005];
set<int>se;
signed main()
{
	int n,x,y,q,su=0,ans=0;
	n=read();
	for(int i=1;i<=n;i++)a[i]=read(),su+=a[i],se.insert(a[i]);
	q=read();
	set<int>::iterator it;
	for(int i=1;i<=q;i++)
	{
		x=read();
		y=read();
		it=se.upper_bound(x);
		if(it!=se.end()&&su-(*it)>=y)
		{
			printf("0\n");
			continue;
		}
		ans=2000000000000000000LL;
		if(it!=se.begin())
		{
			--it;
			ans=min(ans,x-(*it)+max(y-su+(*it),0LL));
		}
		it=se.upper_bound(su-y);
		if(it!=se.end())
		{
			ans=min(ans,max(x-*it,0LL)+y-su+(*it));
		}
		printf("%lld\n",ans);
	}
	return 0;
}