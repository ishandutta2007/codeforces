#include <stdio.h>
#include <vector>
using namespace std;
const int N=105;
vector<int> E[N],bad;
bool done[N];
int sol,tmp;
int main()
{
	int n,m,i,u,v,j;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		scanf("%i %i",&u,&v);
		E[u].push_back(v);
		E[v].push_back(u);
	}
	while(1)
	{
		for(i=1;i<=n;i++)
		{
			if(done[i]) continue;
			tmp=0;
			for(j=0;j<E[i].size();j++)
			{
				tmp+=1-done[E[i][j]];
			}
			if(tmp==1) bad.push_back(i);
		}
		if(bad.empty()) break;
		for(i=0;i<bad.size();i++) done[bad[i]]=1;
		bad.clear();
		sol++;
	}
	printf("%i\n",sol);
	return 0;
}