#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N, D, E;
	cin >> N >> D >> E;
	E *= 5;
	int ans = N;
	for(int i = 0; i <= N; i += D) ans = min(ans, (N-i)%E);
	cout << ans << "\n";
}