#include <bits/stdc++.h>

using namespace std;

#define X first 
#define Y second 
#define FOR(i,L,R) for(auto i=(L);i<=(R);i++)
#define REP(i,L,R) for(auto i=(L);i<(R);i++)

typedef pair<int,int> ii;
typedef long long ll;

const int MOD=1e9+7;
const int N=1e5+10;

int n,width,bussp,persp;
ii a[N];
double solve(){
	bool okay=1;
	for(int i=1;i<=n&&okay;i++) 
		if (1LL*a[i].Y*bussp>1LL*a[i].X*persp) okay=0;
	if (okay) return (width+.0)/persp;
	double ans=0;
	for(int i=1;i<=n;i++)
		ans=max(ans,max((a[i].X+.0)/bussp,(a[i].Y+.0)/persp)+(width-a[i].Y+.0)/persp);
	return ans;
}
int main(){
	scanf("%d%d%d%d",&n,&width,&bussp,&persp);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].X,&a[i].Y);
	printf("%.9f",solve());
}