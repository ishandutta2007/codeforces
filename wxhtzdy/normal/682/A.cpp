#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	map<int, long long> cnt1;
	map<int, long long> cnt2;
	for(int i = 1; i <= n; i++)cnt1[i % 5]++;
	for(int i = 1; i <= m; i++)cnt2[i % 5]++;
	cout << cnt1[0] * cnt2[0] + cnt1[1] * cnt2[4] + cnt1[2] * cnt2[3] + cnt1[3] * cnt2[2] + cnt1[4] * cnt2[1];
}