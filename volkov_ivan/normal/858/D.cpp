#include <iostream>
#include <map>
#include <set>

using namespace std;

const long long M1 = 1e9 + 7, M2 = 1e9 + 9, MAX_N = 70000, b1 = 127, b2 = 131;

long long h1[MAX_N][10], h2[MAX_N][11];
long long pows1[10], pows2[10];

long long my_mod(long long x, long long M) {
	long long ans = x % M;
	if (ans < 0) {
		ans += M;
	}
	return ans;
}

int get_hash1(int k, int l, int r) {
	return my_mod(h1[k][r] - h1[k][l - 1] * pows1[r - l + 1], M1);
}

int get_hash2(int k, int l, int r) {
	return my_mod(h2[k][r] - h2[k][l - 1] * pows2[r - l + 1], M2);
}


int main() {
	map <pair <int, int>, int> hashes;
	set <pair <int, int> > noww;
	int n, r;
	cin >> n;
	string now[n];
	pows1[0] = 1;
	pows2[0] = 1;
	for (int i = 1; i <= 10; i++) {
		pows1[i] = my_mod(pows1[i - 1] * b1, M1);
		pows2[i] = my_mod(pows2[i - 1] * b2, M2);
	}
	for (int i = 0; i < n; i++) {
		cin >> now[i];
		h1[i][0] = 0;
		h2[i][0] = 0;
		noww.clear();
		for (int j = 1; j <= 9; j++) {
			h1[i][j] = my_mod(h1[i][j - 1] * b1 + (now[i][j - 1] - '0' + 1), M1);
			h2[i][j] = my_mod(h2[i][j - 1] * b2 + (now[i][j - 1] - '0' + 1), M2);
		}
		for (int len = 1; len <= 9; len++) {
			for (int l = 1; l <= 9; l++) {
				r = l + len - 1;
				if (r > 9) {
					break;
				}
				noww.insert(make_pair(get_hash1(i, l, r), get_hash2(i, l, r)));
			}
		}
		for (auto uk = noww.begin(); uk != noww.end(); uk++) {
			hashes[(*uk)]++;
		}
	}
	//cout << 57 << endl;
	bool flag;
	for (int i = 0; i < n; i++) {
		flag = 0;
		for (int len = 1; len <= 9; len++) {
			for (int l = 1; l <= 9; l++) {
				r = l + len - 1;
				if (r > 9) {
					break;
				}
				if (hashes[make_pair(get_hash1(i, l, r), get_hash2(i, l, r))] == 1) {
					for (int j = l - 1; j < r; j++) {
						cout << now[i][j];
					}
					cout << endl;
					flag = 1;
					break;
				}
			}
			if (flag) break;
		}
	}
	return 0;
}