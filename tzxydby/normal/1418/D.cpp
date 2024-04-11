#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,q,a[N];
set<int>s;
multiset<int>d;
void zh()
{
	if(s.size()==0||s.size()==1)
		puts("0");
	else
	{
		int ans=0;
		ans-=(*s.begin());
		auto it=s.end();
		it--;
		ans+=(*it);
		auto k=d.end();
		k--;
		ans-=(*k);
		printf("%d\n",ans);
	}
}
void ins(int x)
{
	if(s.size()==0)
		s.insert(x);
	else
	{
		auto it=s.lower_bound(x);
		if(it==s.end())
		{
			auto k=s.end();
			k--;
			int v=(*k);
			d.insert(x-v);
			s.insert(x);
		}	
		else
		{
			if(it==s.begin())
			{
				int v=(*s.begin());
				d.insert(v-x);
				s.insert(x);
			}
			else
			{
				int f=(*it);
				it--;
				int p=(*it);
				d.erase(d.find(f-p));
				d.insert(f-x);
				d.insert(x-p);
				s.insert(x);	
			}
		}
	}
}
void del(int x)
{
	if(s.size()==1)
		s.erase(s.begin());
	else
	{
		s.erase(x);
		auto it=s.lower_bound(x);
		if(it==s.end())
		{
			auto k=s.end();
			k--;
			int v=(*k);
			d.erase(d.find(x-v));
		}	
		else
		{
			if(it==s.begin())
			{
				int v=(*s.begin());
				d.erase(d.find(v-x));
			}
			else
			{
				int f=(*it);
				it--;
				int p=(*it);
				d.insert(f-p);
				d.erase(d.find(f-x));
				d.erase(d.find(x-p));	
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		s.insert(a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++)
		d.insert(a[i]-a[i-1]);
	zh();
	while(q--)
	{
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==0)
			del(x);
		else
			ins(x);
		zh();
	}
	return 0;
}