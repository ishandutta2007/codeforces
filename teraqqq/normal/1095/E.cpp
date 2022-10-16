#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

const int N = 1e6+7;

int ds[N], n, k, dd;
int a, b;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> s;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '(') ds[i+1] = ds[i] + 1;
		if(s[i] == ')') ds[i+1] = ds[i] - 1;
		if(ds[i+1] < 2) ++a;
		if(ds[i+1] < -2) b = 1;
	}

	if(b == 0) for(int i = 0; i < n; ++i) {
		dd = s[i] == '(' ? -2 : 2;
		if(ds[n] + dd == 0 && ds[i+1] + dd >= 0 &&
			(dd > 0 || a == 0))
			++k; 

		if(ds[i+1] < 2) --a;
		if(ds[i+1] < 0) break;
	}

	cout << k;
}