#include<bits/stdc++.h>
#define maxn 1005
using namespace std;
int n,m;
int b[maxn];
vector<int> v[maxn];
int p[maxn];
int to[maxn];
struct data
{
	int c,p,id;
}a[maxn];
bool cmp(data A,data B)
{
	return A.p>B.p;
}
map<int,int> mp;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&a[i].c,&a[i].p);
		a[i].id=i;
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		int x;
		scanf("%d",&x);
		b[i]=x;
		v[x].push_back(i);
		mp[x]++;
	}
	sort(a+1,a+n+1,cmp);
	map<int,int>::iterator it;
	int ans1=0,ans2=0;
	for(int i=1;i<=n;++i)
	{
		it=mp.lower_bound(a[i].c);
		if(it==mp.end())continue;
		ans1++;ans2+=a[i].p;
		to[a[i].id]=v[it->first][p[it->first]];
		p[it->first]++;
		if((it->second)==1)mp.erase(it);
		else (it->second)--;
	}
	printf("%d %d\n",ans1,ans2);
	for(int i=1;i<=n;++i)if(to[i])
	{
		printf("%d %d\n",i,to[i]);
	}
	return 0;
}