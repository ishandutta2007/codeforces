#include<cstdio>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;

typedef pair<int,int> P;

vector<P> team;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int inp,it;
		scanf("%d%d",&inp,&it);
		team.push_back(P(inp,-it));
	}
	sort(team.begin(),team.end());
	int ans=upper_bound(team.begin(),team.end(),team[n-k])-lower_bound(team.begin(),team.end(),team[n-k]);
	printf("%d\n",ans);
	return 0;
}