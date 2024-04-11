#include<bits/stdc++.h>
using namespace std;
long long rd()
{
	char c=getchar();long long x=0;int e=0;
	while(!(c>='0'&&c<='9'))
	{
		if(c=='-')e=1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=x*10+(long long)(c-'0');
		c=getchar();
	}
	return e?-x:x;
}
const int N=500005;
struct node
{
	int x,id;
	long long t;
	bool operator<(const node k)const
	{
		return x<k.x;
	}
}a[N];
int n,m,a1[N],p,b;
long long a2[N],l=-1;
set<pair<long long,int>>s;
multiset<pair<int,int>>t;
vector<pair<long long,int>>v;
void eat(int u,int b)
{
	a1[a[u].id]++;
	a2[a[u].id]+=b;
	a[u].t+=b;
}
int main()
{
	n=rd(),m=rd();
	for(int i=1;i<=n;i++)
		a[i].x=rd(),a[i].t=rd()+a[i].x,a[i].id=i,a2[i]=a[i].t-a[i].x;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		if(a[i].t>l)
		{
			l=a[i].t;
			s.insert(make_pair(l,i));
		}
	}
	while(m--)
	{
		p=rd(),b=rd();
		auto it=s.lower_bound(make_pair(p,0));
		if(it==s.end())
		{
			t.insert(make_pair(p,b));
			continue;
		}
		int u=it->second;
		if(a[u].x>p)
		{
			t.insert(make_pair(p,b));
			continue;
		}
		s.erase(it);
		eat(u,b);
		v.clear();
		for(auto c=t.lower_bound(make_pair(a[u].x,0));c!=t.end();c++)
		{
			p=c->first,b=c->second;
			if(p>a[u].t)
				break;
			eat(u,b);
			v.emplace_back(p,b);
		}
		for(auto i:v)
			t.erase(t.find(i));
		v.clear();
		for(auto c=s.lower_bound(make_pair(a[u].x,0));c!=s.end();c++)
		{
			if(c->first>a[u].t)
				break;
			if(a[c->second].x>a[u].x)
				v.push_back(make_pair(c->first,c->second));
		}
		for(auto i:v)
			s.erase(i);
		s.insert(make_pair(a[u].t,u));
	}
	for(int i=1;i<=n;i++)
		printf("%d %lld\n",a1[i],a2[i]);
	return 0;
}