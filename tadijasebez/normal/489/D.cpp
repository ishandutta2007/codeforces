#include <stdio.h>
#include <vector>
using namespace std;
#define ll long long
const int N=3050;
bool go[N][N];
vector<int> E[N];
ll sol=0;
int main()
{
	int n,m,i,u,v;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		go[u][v]=1;
	}
	for(u=1;u<=n;u++)
	{
		for(v=1;v<=n;v++)
		{
			if(u==v) continue;
			int cnt=0;
			for(i=0;i<E[u].size();i++)
			{
				if(go[E[u][i]][v]) cnt++;
			}
			sol+=(ll)cnt*(cnt-1)/2;
		}
	}
	printf("%lld\n",sol);
	return 0;
}