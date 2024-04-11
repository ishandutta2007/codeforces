#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
#define pb push_back
map<int, vector<int> > E;
map<int, vector<int> >::iterator it;
void DFS(int c, int p)
{
	printf("%i ",c);
	for(int i=0;i<E[c].size();i++) if(E[c][i]!=p) DFS(E[c][i],c);
}
int main()
{
	int n,u,v,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i %i",&u,&v),E[u].pb(v),E[v].pb(u);
	for(it=E.begin();it!=E.end();it++) if((it->second).size()==1){ DFS(it->first,0);break;}
	return 0;
}