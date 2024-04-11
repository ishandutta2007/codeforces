#include<bits/stdc++.h>
using namespace std;
const int max_n=2e5+5;
struct node
{
	int a,b,id;
}c[max_n];
vector<node> v[max_n];
inline bool operator > (const node &x,const node &y)
{
	return x.b>y.b;
}
priority_queue<node,vector<node>,greater<node> > q;
int p[max_n],id[max_n];
set<int> s;
set<int>::iterator it;
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&c[i].a,&c[i].b);
		c[i].id=i;
		v[c[i].a].push_back(c[i]);
	}
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<int(v[i].size());++j)
			q.push(v[i][j]);
		id[i]=q.top().id;
		p[id[i]]=i;
		q.pop();
	}
	for(int x=1;x<=n;++x)
	{
		for(int j=0;j<int(v[x].size());++j)
			s.insert(p[v[x][j].id]);
		int i=id[x];
		it=s.upper_bound(x);
		if(it!=s.end()&&*it<=c[i].b)
		{
			int j=id[*it];
			puts("NO");
			for(int k=1;k<=n;++k)
				printf("%d%c",p[k],k<n?' ':'\n');
			swap(p[i],p[j]);
			for(int k=1;k<=n;++k)
				printf("%d%c",p[k],k<n?' ':'\n');
			return 0;
		}
	}
	puts("YES");
	for(int k=1;k<=n;++k)
		printf("%d%c",p[k],k<n?' ':'\n');
	return 0;
}