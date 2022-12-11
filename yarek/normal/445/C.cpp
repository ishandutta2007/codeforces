#include<iostream>
#include <algorithm>

using namespace std;
int a,b,c,d,e,f,n,m,mx,l,z,r,k,x;
// int INF=1e9+1;
long double cost[503];
long double ans;
void solve()
{
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) 
		cin >> cost[i];
	for(int i = 0; i < m; ++i) {
		cin >> a >> b >> c;
		ans = max(ans, (cost[a] + cost[b])/((long double)(c)));
		
	}
	
	cout.precision(18);
	cout << fixed << ans << "\n";
}
int main()
{
	solve();
	return 0;
}