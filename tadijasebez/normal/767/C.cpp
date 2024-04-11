#include <stdio.h>
#include <vector>
using namespace std;
const int N=1e6+50;
int ans1,ans2;
vector<int> Tree[N];
int NodeSize[N],T[N];
void Calc(int cur)
{
	NodeSize[cur]=T[cur];
	int i;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		Calc(v);
		NodeSize[cur]+=NodeSize[v];
	}
}
int k,root;
int DFS(int cur)
{
	int i,ret=0;
	for(i=0;i<Tree[cur].size();i++)
	{
		int v=Tree[cur][i];
		int tmp=DFS(v);
		if(tmp)
		{
			if(!ret) ret=tmp;
			else ans1=ret,ans2=tmp;
		}
	}
	if(ret && NodeSize[cur]==k*2 && cur!=root) ans1=ret,ans2=cur;
	if(NodeSize[cur]==k) ret=cur;
	return ret;
}
int main()
{
	int n,i,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&x,&T[i]);
		Tree[x].push_back(i);
	}
	root=Tree[0][0];
	Calc(root);
	if(NodeSize[root]%3) return printf("-1\n"),0;
	k=NodeSize[root]/3;
	DFS(root);
	if(ans1 && ans2) printf("%i %i\n",ans1,ans2);
	else printf("-1\n");
	return 0;
}