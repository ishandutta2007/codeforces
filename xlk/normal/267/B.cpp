#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fr(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int>ii;
int v[120],f[10];
int n,x,y,d[10];
vector<ii>a[120];
int w[120];
int F(int x)
{
	return f[x]!=x?f[x]=F(f[x]):x;
}
void dfs(int x)
{
	fe(i,a[x])
		if(v[abs(i->Y)]==0)
		{
			v[abs(i->Y)]=1;
			dfs(i->X);
			printf("%d %c\n",abs(i->Y),i->Y>0?'-':'+');
		}
}
int U(int x,int y)
{
	f[F(x)]=F(y);
}
int abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz;
int main()
{
	cin>>n;
	fr(i,7)
		f[i]=i;
	fo(i,n)
	{
		cin>>x>>y;
		U(x,y);
		a[x].push_back(ii(y,i));
		a[y].push_back(ii(x,-i));
		d[x]++,d[y]++;
	}
	fr(i,7)
		if(d[i]&&F(i)==i)
			abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz++;
	if(abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz>1)
	{
		puts("No solution");
		return 0;
	}
	int c=0,s;
	fr(i,7)
		if(d[i]&1)
			c++;
	if(c>2)
	{
		puts("No solution");
		return 0;
	}
	fr(i,7)
		if(d[i])
			s=i;
	fr(i,7)
		if(d[i]&1)
			s=i;
	dfs(s);
}