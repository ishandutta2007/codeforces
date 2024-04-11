#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
int n,a[N],v[N];
vector<int>x,y;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=i-a[i];
			v[i]=0;
		}
		x.clear(),y.clear();
		int u=1;
		while(!v[u])
		{
			v[u]=1;
			x.push_back(u);
			u=a[u];
		}
		while(x.back()!=u)
		{
			y.push_back(x.back());
			x.pop_back();
		}
		y.push_back(u);
		printf("%d\n",y.size());
		for(auto i:y)
			printf("%d ",i);
		puts("");
	}
	return 0;
}