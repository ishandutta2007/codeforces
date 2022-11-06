#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <deque>
#include <cassert>
#include <random>  
#include <ctime>
#define pb push_back
#define x first
#define y second
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
using namespace std;

template<typename T1, typename T2>inline void chkmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T1, typename T2>inline void chkmax(T1 &x, T2 y) { if (x < y) x = y; }
typedef long long base;
typedef pair <int, int> point;


const string FILENAME = "input";
const int MAXN = 1e6 + 1;

int n;
map <int, int> cnt[20];
vector <string> arr;

int main() {
	ios::sync_with_stdio(0);
	//read(FILENAME);
	srand(time(0));
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		arr.pb(s);
		set <int> res[20];
		for (int L = 0; L < s.size(); ++L) {
			int num = 0;
			for (int R = L; R < s.size(); ++R) {
				num *= 10;
				num += s[R] - '0';
				if (res[R - L].count(num))
					continue;
				++cnt[R - L][num];
				res[R - L].insert(num);
			}
		}
	}
	for (auto s : arr) {
		int ans_len = 10, num_ans = -1;
		for (int L = 0; L < s.size(); ++L) {
			int num = 0;
			for (int R = L; R < s.size() && (R - L + 1) < ans_len; ++R) {
				num *= 10;
				num += s[R] - '0';
				if (cnt[R - L][num] == 1) {
					ans_len = R - L + 1;
					num_ans = num;
				}
			}
		}
		string res = "";
		for (int i = 0; i < ans_len; ++i) {
			res += char('0' + num_ans % 10);
			num_ans /= 10;
		}
		reverse(res.begin(), res.end());
			cout << res << '\n';
	}
}