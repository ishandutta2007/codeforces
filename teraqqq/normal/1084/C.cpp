#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 1e5+7;
const int M = 1e9+7;

char s[N]; 
int a=0, b=1, res;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> s;
	for(int i = 0; s[i] != 0; ++i) {
		if(s[i] == 'b') { a = res; }
		if(s[i] != 'a') continue;

		res = (res + 1LL + a) % M;
		b = (b * 2LL) % M;
	}

	cout << res;
}