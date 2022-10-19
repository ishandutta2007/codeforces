#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,m,a[N],v[N];
vector<int>c[N],a1,a2;
void add(int x,int y)
{
	a1.push_back(x);
	a2.push_back(y);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
	{
		if(i!=a[i]&&!v[i])
		{
			m++;
			c[m].push_back(i),v[i]=1;
			for(int x=a[i];x!=i;x=a[x])
				c[m].push_back(x),v[x]=1;
		}
	}
	while(m>=2)
	{
		auto &x=c[m],&y=c[m-1];
		add(x[0],y[0]);
		for(int i=1;i<x.size();i++)
			add(y[0],x[i]);
		for(int i=1;i<y.size();i++)
			add(x[0],y[i]);
		add(x[0],y[0]);
		m-=2;
	}
	if(m)
	{
		auto &x=c[1];
		if(x.size()==2)
		{
			int p=0;
			if(!p&&x[0]!=1&&x[1]!=1) p=1;
			if(!p&&x[0]!=2&&x[1]!=2) p=2;
			if(!p&&x[0]!=3&&x[1]!=3) p=3;
			add(x[0],p),add(x[1],p),add(x[0],p);
		}
		else
		{
			add(x[0],x[1]),add(x[1],x[2]);
			for(int i=3;i<x.size();i++)
				add(x[1],x[i]);
			add(x[0],x[2]),add(x[0],x[1]);
		}
	}
	printf("%d\n",a1.size());
	for(int i=0;i<a1.size();i++)
		printf("%d %d\n",a1[i],a2[i]);
	return 0;
}