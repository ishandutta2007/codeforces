#include <stdio.h>
#include <map>
using namespace std;
#define ll long long
const int N=100050;
map<int,int> cost;
ll sol;
int max(int a, int b){ return a>b?a:b;}
int main()
{
	int n,m,x,y;
	scanf("%i",&n);
	while(n--) scanf("%i %i",&x,&y),sol+=y>cost[x]?y-cost[x]:0,cost[x]=max(cost[x],y);
	scanf("%i",&m);
	while(m--) scanf("%i %i",&x,&y),sol+=y>cost[x]?y-cost[x]:0,cost[x]=max(cost[x],y);
	printf("%lld\n",sol);
	return 0;
}