#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
int n;
long long T,ans,all,resA[Maxn],sum[Maxn];
struct A
{
	int val,id;
	bool operator < (const A &tmp) const
	{
		return val<tmp.val;
	}
}a[Maxn];
int lowbit(int x)
{
	return x&-x;
}
void change(int x,long long y)
{
	for(int i=x;i<=n;i+=lowbit(i))
		sum[i]+=y;
}
long long ask(int x)
{
	long long ans=0;
	while(x)
	{
		ans+=sum[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	scanf("%d%lld",&n,&T);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].val),resA[i]=a[i].val,all+=a[i].val,a[i].id=i,change(i,a[i].val);
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--)
	{
		if(T/ask(a[i].id)==0){all-=a[i].val;change(a[i].id,-a[i].val);continue;}
		if(T/all!=0)
		{
			ans+=(T/all)*i;
			T%=all;
		}
		if(T>=ask(a[i].id))
		{
			for(int j=1;j<=n;j++)
				if(T>=resA[j]) ans++,T-=resA[j];
		}
		change(a[i].id,-a[i].val);
		all-=a[i].val;
	}
	printf("%lld",ans);
	return 0;
}