#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=10000000;
int min(int a, int b){ return a>b?b:a;}
int max(int a, int b){ return a>b?a:b;}
vector<int> c;
map<int,int> Front,Back;
int main()
{
	int n,s,i,f,b;
	scanf("%i",&n);
	s=(n+1)/2;
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&f,&b);
		c.push_back(f);
		c.push_back(b);
		if(f==b) Front[f]++;
		else Front[f]++,Back[b]++;
	}
	sort(c.begin(),c.end());
	c.erase(unique(c.begin(),c.end()),c.end());
	int sol=inf;
	for(i=0;i<c.size();i++) if(Front[c[i]]+Back[c[i]]>=s) sol=min(sol,max(0,s-Front[c[i]]));
	if(sol==inf) printf("-1\n");
	else printf("%i\n",sol);
	return 0;
}