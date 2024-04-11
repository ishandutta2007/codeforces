#include<bits/stdc++.h>
using namespace std;
int n,m,k;
vector<pair<int,long long>>a,b;
vector<pair<int,long long>>cal(vector<pair<int,long long>>v)
{
	vector<pair<int,long long>>g;
	for(int i=0,j=0;i<v.size();i=j+1)
	{
		j=i;
		while(j+1<v.size()&&v[j+1].first==v[i].first)
			j++;
		long long s=0;
		for(int x=i;x<=j;x++)
			s+=v[x].second;
		g.emplace_back(v[i].first,s);
	}
	return g;
}
void sol()
{
	a.clear(),b.clear();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x,c=1;
		scanf("%d",&x);
		while(x%m==0)
			x/=m,c*=m;
		a.emplace_back(x,c);
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++)
	{
		int x,c=1;
		scanf("%d",&x);
		while(x%m==0)
			x/=m,c*=m;
		b.emplace_back(x,c);
	}
	a=cal(a);
	b=cal(b);
	if(a==b)
		puts("Yes");
	else
		puts("No");
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}