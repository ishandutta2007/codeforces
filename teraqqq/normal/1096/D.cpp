#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <fstream>

using namespace std;

typedef long long ll;

string s;
int n;
ll a, b, c, d, x;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		if(s[i] == 'h') a += x;
		if(s[i] == 'a') b = min(a, b+x);
		if(s[i] == 'r') c = min(b, c+x);
		if(s[i] == 'd') d = min(c, d+x);
	}

	cout << d;
}