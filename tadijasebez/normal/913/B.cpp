#include <stdio.h>
#include <vector>
using namespace std;
const int N=1050;
vector<int> E[N];
bool ok=1;
int DFS(int u)
{
	if(E[u].size()==0) return 1;
	int sum=0;
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		sum+=DFS(v);
	}
	if(sum<3) ok=0;
	return 0;
}
int main()
{
	int n,u,i;
	scanf("%i",&n);
	for(i=2;i<=n;i++) scanf("%i",&u),E[u].push_back(i);
	DFS(1);
	if(ok) printf("Yes\n");
	else printf("No\n");
	return 0;
}