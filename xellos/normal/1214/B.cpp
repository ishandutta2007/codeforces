#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	int B, G, N;
	cin >> B >> G >> N;
	B = min(B, N);
	G = min(G, N);
	cout << B+G-N+1 << "\n";
}