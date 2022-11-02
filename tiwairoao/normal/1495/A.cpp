#include <bits/stdc++.h>

std::vector<int>vx, vy; int n;
int mabs(int x) {return x < 0 ? -x : x;}

void solve() {
	vx.clear(), vy.clear(), scanf("%d", &n);
	for(int i=1,x,y;i<=2*n;i++) {
		scanf("%d%d", &x, &y);
		if( x == 0 ) vy.push_back(mabs(y));
		if( y == 0 ) vx.push_back(mabs(x));
	}
	std::sort(vx.begin(), vx.end());
	std::sort(vy.begin(), vy.end());
	
	double ans = 0;
	for(int i=0;i<n;i++)
		ans += sqrt((double)vx[i] * vx[i] + (double)vy[i] * vy[i]);
	printf("%.10f\n", ans);
}

int main() {
	int T; scanf("%d", &T);
	while( T-- ) solve();
}