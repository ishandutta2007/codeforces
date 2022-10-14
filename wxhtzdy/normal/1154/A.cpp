#include <bits/stdc++.h>

using namespace std;

const int N = 1e6;

int main() { 
	vector<int> v(4);
	for (int i = 0; i < 4; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	int a = v[0], b = v[1], c = v[2], d = v[3];         
	cout << d - c << " " << d - b << " " << d - a;
}