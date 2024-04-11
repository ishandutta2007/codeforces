#include<iostream>
#include<algorithm>
using namespace std;
#define fo(i,n) for(int i=1;i<=n;i++)
int n,m,x,y,z;
vector<int>a[101000];
int main()
{
	cin>>n>>m;
	fo(i,m)
		cin>>x>>y,a[x].push_back(y),a[y].push_back(x);
	fo(i,n)
		z+=a[i].size()&1;
	fo(i,n)
		if(a[i].size()==2)
		{
			x=a[i][0],y=a[i][1];
			if(x==y)
				a[x].clear(),z+=2;
			else
				a[x][a[x][0]!=i]=y,a[y][a[y][0]!=i]=x;
		}
	printf("%d %d\n",z/2,m);
}