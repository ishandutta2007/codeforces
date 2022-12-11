#include <iostream>
#include <vector>

using namespace std;

const int N = 3007;
string s[N], t[N];
int l[N], r[N];
string ans1, ans2;
vector <string> same;
bool ssame[N];

int check1(string s, string t) {
	int k = s.length();
	s += t;
	int n = s.length();
    int z[n];
    z[0] = n;
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
        int len = 0;
        if (i < r) {
            len = min(z[i - l], r - i);
        }
        while (i + len < n && s[len] == s[i + len]) len++;
        z[i] = len;
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
	for (int i = k; i < s.length(); i++) if (z[i] >= k) return i - k;
	return -1;
}

bool check(string ss, int n) {
	for (int i = 0; i < n; i++) {
		if (ssame[i]) {
			if (check1(ss, s[i]) >= 0) return 0;
		} else {
			if (check1(ss, s[i]) < l[i]) return 0;
		}
		//cout << ss << ' ' << s[i] << check1(ss, s[i]) << endl;
	}
	return 1;
}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> s[i];
	for (int i = 0; i < n; i++) cin >> t[i];
	for (int i = 0; i < n; i++) {
		if (s[i] == t[i]) {
			same.push_back(s[i]);
			ssame[i] = 1;
		} else ssame[i] = 0;
	}
	ans1 = ans2 = "";
	for (int i = 0; i < n; i++) {
		if (ssame[i]) continue;
		string a1 = "", a2 = "";
		l[i] = -1, r[i] = -1;
		for (int j = 0; j < s[i].length(); j++) {
			if (s[i][j] != t[i][j]) {
				r[i] = j;
				if (l[i] == -1) l[i] = j;
			}
		}
		//ans1[i] = ans2[i] = "";
		if (l[i] == -1) continue;
		for (int j = l[i]; j <= r[i]; j++) {
			a1 += s[i][j];
			a2 += t[i][j];
		}
		if (ans1 == "") {
			ans1 = a1;
			ans2 = a2;
		} else {
			if (ans1 != a1 || ans2 != a2) {
				cout << "NO" << endl;
				return 0;
			}
		}
	}
	while (1) {
		char now = '#';
		bool flag = 1;
		for (int i = 0; i < n; i++) {
			if (ssame[i]) continue;
			//cout << i << ' ' << l[i] << endl;
			if (l[i] == 0) { flag = 0; break;}
			if (now == '#') now = s[i][l[i] - 1];
			else if (now != s[i][l[i] - 1]) {flag = 0; break;}
		}
		//cout << 93 << endl;
		if (!flag) break;
		//cout << 94 << endl;
		ans1 = now + ans1;
		ans2 = now + ans2;
		for (int i = 0; i < n; i++) {
			if (!ssame[i]) l[i]--;
		}
	}		
	while (1) {
		char now = '#';
		bool flag = 1;
		for (int i = 0; i < n; i++) {
			if (ssame[i]) continue;
			if (r[i] == (int) s[i].length() - 1) { flag = 0; break;}
			if (now == '#') now = s[i][r[i] + 1];
			else if (now != s[i][r[i] + 1]) {flag = 0; break;}
		}
		if (!flag) break;
		ans1 += now; 
		ans2 += now;
		for (int i = 0; i < n; i++) {
			if (!ssame[i]) r[i]++;
		}
	}
	//cout << ans1 << endl << ans2 << endl;
	if (check(ans1, n)) cout << "YES" << endl << ans1 << endl << ans2 << endl;
	else cout << "NO" << endl;
	return 0;
}