#include <bits/stdc++.h>
using namespace std;
string s;
vector<char> A;
vector<char> B;
int main() {
	cin >> s;
	int l = 0;
	int r = s.size() - 1;
	while (l <= r) {
		if (l > r) {
			break;
		} else if (r - l < 3) {
			A.push_back(s[l]);
			break;
		} else {
			int c[4] = {};
			c[s[l] - 'a']++;
			c[s[l + 1] - 'a']++;
			c[s[r] - 'a']++;
			c[s[r - 1] - 'a']++;
			l += 2;
			r -= 2;
			for (int i = 0; i < 3; i++) {
				if (c[i] >= 2) {
					A.push_back('a' + i);
					B.push_back('a' + i);
					break;
				}
			}
		}
	}
	for (int i = 0; i < A.size(); i++) {
		printf("%c", A[i]);
	}
	for (int i = B.size() - 1; i >= 0; i--) {
		printf("%c", B[i]);
	}
	printf("\n");
	return 0;
}