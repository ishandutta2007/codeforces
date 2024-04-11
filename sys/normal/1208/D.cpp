#include <bits/stdc++.h>
using namespace std;
const int Maxn=200005;
long long sum[Maxn];
int n,ans[Maxn];
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int y)
{
	for(int i=x;i<=n;i+=lowbit(i))
		sum[i]+=y;
}
long long ask(int x)
{
	long long tmp=0;
	for(int i=x;i;i-=lowbit(i))
		tmp+=sum[i];
	return tmp;
}
long long a[Maxn];
set <int> Se;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		add(i,i),scanf("%lld",&a[i]),Se.insert(i);
	for(int i=n;i>=1;i--)
	{
		int l=0,r=n;
		while(l+1<=r)
		{
			int mid=(l+r)/2;
			if(ask(mid)>=a[i]) r=mid;
			else l=mid+1;
		}
		l++;
		l=*Se.lower_bound(l);
		Se.erase(Se.find(l));
		ans[i]=l;
		add(l,-l);
	}
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}