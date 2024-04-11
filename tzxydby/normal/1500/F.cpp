#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n;
long long l,r,k=1,b,m,a[N],tg[N],d[N],w[N],q[N];
set<long long>s;
int main()
{
	scanf("%d%*d",&n);
	for(int i=1;i<=n-2;i++)
		scanf("%lld",&w[i]);
	l=0,r=w[1];
	for(int i=2;i<=n-2;i++)
	{
		if((w[i]>=l&&w[i]<=r)||s.find((w[i]-b)/k)!=s.end())
		{
			tg[i]=1;
			l=0,r=w[i];
			s.clear();
			k=1,b=0;
		}
		else
		{
			if(l<=r&&l>w[i])
				l=-1,r=-2;
			while(!s.empty())
			{
				auto it=(k==1?--s.end():s.begin());
				if(k*(*it)+b<=w[i])
					break;
				s.erase(it);
			}
			if(l>r&&s.empty())
			{
				puts("NO");
				return 0;
			}
			if(l<=r)
				q[i]=l;
			else
				q[i]=k*(*s.begin())+b;
			if(l<=r)
			{
				l=w[i]-l;
				r=w[i]-r;
				swap(l,r);
			}
			k=-k;
			b=w[i]-b;
			s.insert((w[i]-b)*k);
		}
	}
	if(l<=r)
		d[n-2]=l;
	else
		d[n-2]=k*(*s.begin())+b;
	for(int i=n-2;i>1;i--)
	{
		if(tg[i])
			d[i-1]=w[i];
		else
			d[i-1]=(d[i]==w[i]?q[i]:w[i]-d[i]);
	}
	a[2]=w[1]-d[1];
	a[3]=w[1];
	for(int i=4;i<=n;i++)
	{
		a[i]=a[i-1]+d[i-2];
		if(max(a[i],max(a[i-1],a[i-2]))-min(a[i],min(a[i-1],a[i-2]))!=w[i-2])
			a[i]=a[i-1]-d[i-2];
	}
	for(int i=1;i<=n;i++)
		m=min(m,a[i]);
	puts("YES");
	for(int i=1;i<=n;i++)
		printf("%lld ",a[i]-m);
	return 0;
}