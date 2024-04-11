#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
const int N=100050;
vector<int> pos[N];
int main()
{
    int n,x,i;
    scanf("%i",&n);
    for(i=0;i<2*n;i++) scanf("%i",&x),pos[x].pb(i);
	ll ans=pos[1][0]+pos[1][1];
	for(i=2;i<=n;i++)
	{
		int a=abs(pos[i-1][0]-pos[i][0])+abs(pos[i-1][1]-pos[i][1]);
		int b=abs(pos[i-1][0]-pos[i][1])+abs(pos[i-1][1]-pos[i][0]);
		int add=min(a,b);
		ans+=add;
	}
	printf("%lld\n",ans);
	return 0;
}