#include<iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second
#define N 100020
#define P push_back
using namespace std;
typedef pair<int,int>ii;
vector<ii>a[N];
vector<int>z;
int c[N],f[N],g[N],h[N],v[N],n,m,x,y,cnt,o,i;
void dfs(int x,int y)
{
	v[x]=1,c[x]=c[y]^1;
	for(auto&i:a[x])
		if(i.X==y)
			;
		else if(!v[i.X])
			h[i.X]=i.Y,dfs(i.X,x),f[x]+=f[i.X],g[x]+=g[i.X];
		else if(v[i.X]&1)
			c[i.X]==c[x]?cnt++,o=i.Y,f[x]++:g[x]++;
		else
			c[i.X]==c[x]?f[x]--:g[x]--;
	v[x]=2;
}
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++)
		cin>>x>>y,a[x].P(ii(y,i)),a[y].P(ii(x,i));
	for(i=1;i<=n;i++)
		if(!v[i])
			dfs(i,0);
	if(cnt==0)
		for(i=1;i<=m;i++)
			z.P(i);
	else
	{
		if(cnt==1)
			z.P(o);
		for(i=1;i<=n;i++)
			if(f[i]==cnt&&!g[i])
				z.P(h[i]);
		sort(z.begin(),z.end());
	}
	cout<<z.size()<<endl;
	for(int i:z)
		cout<<i<<' ';
}