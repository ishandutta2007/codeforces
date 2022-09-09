#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
#define pb push_back
const int N=5050;
bool was[N];
void Init(){ for(int i=0;i<N;i++) was[i]=0;}
vector<int> ord,E[N];
void DFS(int u)
{
	was[u]=1;
	//printf("%i<-\n",u);
	for(int i=0;i<E[u].size();i++)
	{
		int v=E[u][i];
		//printf("u:%i v:%i\n",u,v);
		if(!was[v]) DFS(v);
	}
	ord.pb(u);
}
int main()
{
    int n,m,u,v,i,s,sol=0;
    scanf("%i %i %i",&n,&m,&s);
    for(i=1;i<=m;i++) scanf("%i %i",&u,&v),E[u].pb(v);//,printf("%i -> %i\n",u,v);
    DFS(s);
    for(i=1;i<=n;i++) if(!was[i]) DFS(i);
    Init();
    for(i=ord.size()-1;~i;i--)
	{
		//printf("%i\n",ord[i]);
		if(!was[ord[i]])
		{
			//printf("->%i\n",ord[i]);
			sol+=(s!=ord[i]);
			DFS(ord[i]);
		}
	}
	printf("%i\n",sol);
        return 0;
}