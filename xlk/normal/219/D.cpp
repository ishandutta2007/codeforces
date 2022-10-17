#include<iostream>
#include<algorithm>
#include<vector>
#define X first
#define Y second
using namespace std;
#define fe(i,n) for(__typeof(n.begin()) i=n.begin();i!=n.end();i++)
typedef pair<int,int>ii;
vector<ii>a[200020];
int g[200020];
int n,x,y;
int F(int x,int y)
{
	int _=0;
	fe(i,a[x])
		if(i->X!=y)
			_+=F(i->X,x)+i->Y;
	return _;
}
void G(int x,int y)
{
	fe(i,a[x])
		if(i->X!=y)
			g[i->X]=g[x]+(i->Y?-1:1),G(i->X,x);
}
int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>x>>y;
		a[x].push_back(ii(y,0));
		a[y].push_back(ii(x,1));
	}
	g[1]=F(1,0);
	G(1,0);
	x=*min_element(g+1,g+n+1);
	cout<<x<<endl;
	for(int i=1;i<=n;i++)
		if(g[i]==x)
			cout<<i<<' ';
	return 0;
}