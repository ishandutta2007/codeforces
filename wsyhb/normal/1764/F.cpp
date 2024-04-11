#include<bits/stdc++.h>
using namespace std;
const int max_n=2e3+5;
long long f[max_n][max_n],dis[max_n][max_n];
typedef pair<long long,int> P;
set<P> edge[max_n];
inline void solve(vector<int> now)
{
	if((int)now.size()==1)
		return;
	long long mn=1e18;
	int p=-1,q=-1;
	for(int x:now)
	{
		if(!edge[x].empty()&&edge[x].begin()->first<mn)
		{
			mn=edge[x].begin()->first;
			p=x,q=edge[x].begin()->second;
		}
	}
	assert(~p);
	printf("%d %d %lld\n",p,q,dis[p][q]);
	vector<int> L,R;
	for(int x:now)
	{
//		fprintf(stderr,"x=%d dis[x][p]=%lld dis[x][q]=%lld\n",x,dis[x][p],dis[x][q]);
		assert(dis[x][p]!=dis[x][q]);
		if(dis[x][p]<dis[x][q])
			L.push_back(x);
		else
			R.push_back(x);
	}
	for(int X:L)
		for(int Y:R)
		{
			int x=X,y=Y;
			if(x>y)
				swap(x,y);
			edge[x].erase(P(dis[x][y],y));
		}
	solve(L),solve(R);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j)
		{
			scanf("%lld",&f[i][j]);
			f[j][i]=f[i][j];
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			long long v=f[i][i]+f[j][j]-2*f[i][j];
			assert(v%n==0);
			dis[i][j]=v/n;
			if(i<j)
				edge[i].insert(P(dis[i][j],j));
		}
	vector<int> U;
	for(int i=1;i<=n;++i)
		U.push_back(i); 
	solve(U);
	return 0;
}