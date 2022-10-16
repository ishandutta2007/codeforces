#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

int w, h, d[2], u[2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> w >> h;
	for(int i = 0; i < 2; ++i)
		cin >> u[i] >> d[i];
	for(int i = h; i != 0; --i) {
		w += i;
		for(int j = 0; j < 2; ++j)
			if(i == d[j]) w -= u[j];
		w = max(0, w);
	}

	cout << w;
}