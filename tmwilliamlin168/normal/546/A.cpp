#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k, n, w, t=0;
	cin >> k >> n >> w;
	for(int i=1; i<=w; ++i)
		t+=i*k;
	cout << max(t-n, 0);
}