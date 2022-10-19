#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,m,a[N],b[N],sa,sb,pa,pb;
bitset<N*N>da[N],db[N];
vector<int>a0,a1,b0,b1,x0,x1,x2,y0,y1,y2;
void sol()
{
	sa=sb=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),sa+=a[i];
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]),sb+=b[i];
	if(n!=m||sa&1||sb&1)
	{
		puts("No");
		return;
	}
	sa>>=1,sb>>=1;
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	for(int i=0;i<=n;i++)
		da[i]=db[i]=0;
	da[0][0]=db[0][0]=1;
	for(int i=1;i<=n;i++)
		da[i]=da[i-1]|(da[i-1]<<a[i]);
	for(int i=1;i<=n;i++)
		db[i]=db[i-1]|(db[i-1]<<b[i]);
	if(!da[n][sa]||!db[n][sb])
	{
		puts("No");
		return;
	}
	a0.clear(),a1.clear(),b0.clear(),b1.clear();
	x0.clear(),x1.clear(),x2.clear(),y0.clear(),y1.clear(),y2.clear();
	pa=sa;
	for(int i=n;i>=1;i--)
	{
		if(da[i-1][pa])
			a0.push_back(a[i]);
		else
		{
			a1.push_back(a[i]);
			pa-=a[i];
		}
	}
	pb=sb;
	for(int i=n;i>=1;i--)
	{
		if(db[i-1][pb])
			b0.push_back(b[i]);
		else
		{
			b1.push_back(b[i]);
			pb-=b[i];
		}
	}
	puts("Yes");
	if(a0.size()<=b0.size())
	{
		for(int i=0;i<a0.size();i++)
			x0.push_back(a0[i]),y0.push_back(b0[i]);
		for(int i=a0.size();i<b0.size();i++)
			x1.push_back(a1[i-a0.size()]),y1.push_back(b0[i]);
		for(int i=0;i<b1.size();i++)
			x2.push_back(a1[i+b0.size()-a0.size()]),y2.push_back(b1[i]);
		sort(x0.begin(),x0.end());
		reverse(x0.begin(),x0.end());
		sort(x1.begin(),x1.end());
		reverse(x1.begin(),x1.end());
		sort(x2.begin(),x2.end());
		reverse(x2.begin(),x2.end());
		sort(y0.begin(),y0.end());
		sort(y1.begin(),y1.end());
		sort(y2.begin(),y2.end());
		int x=0,y=0;
		for(int i=0;i<x0.size();i++)
		{
			x+=x0[i];
			printf("%d %d\n",x,y);
			y+=y0[i];
			printf("%d %d\n",x,y);
		}
		for(int i=0;i<x1.size();i++)
		{
			x-=x1[i];
			printf("%d %d\n",x,y);
			y+=y1[i];
			printf("%d %d\n",x,y);
		}
		for(int i=0;i<x2.size();i++)
		{
			x-=x2[i];
			printf("%d %d\n",x,y);
			y-=y2[i];
			printf("%d %d\n",x,y);
		}
	}
	else
	{
		for(int i=0;i<b0.size();i++)
			x0.push_back(a0[i]),y0.push_back(b0[i]);
		for(int i=b0.size();i<a0.size();i++)
			x1.push_back(a0[i]),y1.push_back(b1[i-b0.size()]);
		for(int i=0;i<a1.size();i++)
			x2.push_back(a1[i]),y2.push_back(b1[i+a0.size()-b0.size()]);
		sort(x0.begin(),x0.end());
		sort(x1.begin(),x1.end());
		sort(x2.begin(),x2.end());
		sort(y0.begin(),y0.end());
		reverse(y0.begin(),y0.end());
		sort(y1.begin(),y1.end());
		reverse(y1.begin(),y1.end());
		sort(y2.begin(),y2.end());
		reverse(y2.begin(),y2.end());
		int x=0,y=0;
		for(int i=0;i<x0.size();i++)
		{
			y+=y0[i];
			printf("%d %d\n",x,y);
			x+=x0[i];
			printf("%d %d\n",x,y);
		}
		for(int i=0;i<x1.size();i++)
		{
			y-=y1[i];
			printf("%d %d\n",x,y);
			x+=x1[i];
			printf("%d %d\n",x,y);
		}
		for(int i=0;i<x2.size();i++)
		{
			y-=y2[i];
			printf("%d %d\n",x,y);
			x-=x2[i];
			printf("%d %d\n",x,y);
		}
	}
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}