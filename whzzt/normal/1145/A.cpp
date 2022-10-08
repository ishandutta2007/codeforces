#include <bits/stdc++.h>

using namespace std;

const int N = 20;
int ans = 1, n, a[N];

void solve(int l, int r){
	if (l == r) return ;
	int mid = (l + r) >> 1; bool ok = true;
	for (int i = l; i < r; ++i) if (a[i] > a[i + 1]) ok = false;
	if (ok) ans = max(ans, r - l + 1); 
	else solve(l, mid), solve(mid + 1, r);
}

int main(){
	cin >> n;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	solve(1, n);
	cout << ans << endl;
}