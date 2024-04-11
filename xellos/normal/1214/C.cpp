#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int N;
	string S;
	cin >> N >> S;
	int sum = 0, mi = 0;
	for(int i = 0; i < N; i++) {
		sum += (S[i] == '(') ? 1 : -1;
		mi = min(mi, sum);
	}
	if(sum != 0 || mi <= -2) cout << "No\n";
	else cout << "Yes\n";
}