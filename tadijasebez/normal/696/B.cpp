#include <stdio.h>
#include <vector>
using namespace std;
const int N=100050;
int Depth[N],NodeSize[N];
vector<int> Tree[N];
void DFS(int cur, int prev, int depth)
{
	Depth[cur]=depth;
	NodeSize[cur]=1;
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		if(v!=prev)
		{
			DFS(v,cur,depth+1);
			NodeSize[cur]+=NodeSize[v];
		}
	}
}
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=2;i<=n;i++) scanf("%i",&x),Tree[x].push_back(i);
	DFS(1,0,1);
	for(i=1;i<=n;i++)
	{
		printf("%i",(n-NodeSize[i]-Depth[i]+1)/2+Depth[i]);
		if((n-NodeSize[i]-Depth[i]+1)%2==1) printf(".5");
		printf(" ");
	}
	printf("\n");
	return 0;
}