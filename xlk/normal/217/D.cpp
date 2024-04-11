#include<iostream>
#include<bitset>
using namespace std;
int x,m,t,c[120],p=1000000007,z;
int dfs(int x,bitset<120>y,long long w)
{
	if(x>m/2)
		return z=(z+w)%p;
	dfs(x+1,y,w);
	c[x]&&!y[x]&&dfs(x+1,y|y>>x|y<<m-x|y<<x|y>>m-x,w*c[x]%p);
}
int main()
{
	for(cin>>x>>m>>t;t--;x%=m,c[min(x,m-x)]++)
		cin>>x;
	dfs(0,bitset<120>(1),1);
	cout<<z;
}