#include<bits/stdc++.h>
using namespace std;
const int N=400005;
int n,v[N];
vector<int>a,b;
void sol()
{
	scanf("%d",&n);
	for(int i=1;i<=n*2;i++)
		v[i]=0;
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		v[x]=1;
	}
	a.clear();
	b.clear();
	for(int i=1;i<=n*2;i++)
	{
		if(v[i])
			a.push_back(i);
		else
			b.push_back(i);
	}
	int m1,m2;
	{
		int l=0,r=n+1;
		while(r-l>1)
		{
			int m=l+r>>1;
			int fl=1;
			for(int i=0;i<m;i++)
				if(a[i]>b[n-m+i])
					fl=0;
			if(fl)
				l=m;
			else
				r=m;
		}
		m1=l;
	}
	{
		int l=0,r=n+1;
		while(r-l>1)
		{
			int m=l+r>>1;
			int fl=1;
			for(int i=0;i<m;i++)
				if(a[n-m+i]<b[i])
					fl=0;
			if(fl)
				l=m;
			else
				r=m;
		}
		m2=l;
	}
	printf("%d\n",m1-(n-m2)+1);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}