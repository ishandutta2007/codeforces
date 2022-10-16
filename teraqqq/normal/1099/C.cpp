#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 703;

char s[N], r[N];
int n, k, l, ml;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s >> k;
	for(int i = 0; s[i] != 0; ++i) {
		if(s[i] != '*' && s[i] != '?') ++ml;
		if(s[i] == '*' || s[i] == '?') --ml;
	}

	if(ml <= k) {
		int dk = k - ml;
		for(int i = 0; s[i] != 0; ++i) {
			if(s[i+1] == '*') {
				for(; dk; --dk) r[l++] = s[i];
				++i;
			}
			else if(s[i+1] == '?') {
				if(dk) {
					r[l++] = s[i];
					dk--;
				}
				++i;
			}
			else r[l++] = s[i];
		}

		if(dk) cout << "Impossible";
		else cout << r;
	}
	else cout << "Impossible";
}