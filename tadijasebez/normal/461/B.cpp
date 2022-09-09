#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
const int mod=1e9+7;
vector<int> Tree[N];
int DP[N][2],x[N];
void DFS(int cur)
{
	DP[cur][0]=1;
	DP[cur][1]=0;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		DFS(v);
		DP[cur][1]=1ll*DP[cur][1]*DP[v][0]%mod;
		DP[cur][1]=(DP[cur][1]+1ll*DP[cur][0]*DP[v][1]%mod)%mod;
		DP[cur][0]=1ll*DP[cur][0]*DP[v][0]%mod;
	}
	if(x[cur]==1)
		DP[cur][1]=DP[cur][0];
	else DP[cur][0]=(DP[cur][0]+DP[cur][1])%mod;
}
int main()
{
	int n,i,y;
	scanf("%i",&n);
	for(i=1;i<n;i++) scanf("%i",&y),Tree[y].push_back(i);
	for(i=0;i<n;i++) scanf("%i",&x[i]);
	DFS(0);
	printf("%i\n",DP[0][1]);
	return 0;
}