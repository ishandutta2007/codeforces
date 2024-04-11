#include <stdio.h>
#include <vector>
using namespace std;
#define pb push_back
const int N=1005;
vector<int> cnt[N];
vector<int> sol[N];
vector<int> tmp;
int sz,sum;
void DFS(int d)
{
	if(cnt[d].size()>0)
	{
		sol[cnt[d].back()]=tmp;
		cnt[d].pop_back();
		sz++;
		return;
	}
	if(sz==sum) return;
	tmp.pb(0);
	DFS(d+1);
	tmp.pop_back();
	tmp.pb(1);
	DFS(d+1);
	tmp.pop_back();
}
int main()
{
	int n,i,j,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x),sum++,cnt[x].pb(i);
	DFS(0);
	if(sz==sum)
	{
		printf("YES\n");
		for(i=1;i<=n;i++)
		{
			for(j=0;j<sol[i].size();j++) printf("%i",sol[i][j]);
			printf("\n");
		}
	}
	else printf("NO\n");
	return 0;
}