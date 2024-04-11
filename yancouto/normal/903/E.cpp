#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#	define debug(args...) ((void) 0)
#else
#	define debug(args...) fprintf(stderr, args)
#endif

int n, k;

string s[11234];

void imp() { puts("-1"); exit(0); }

vector<int> dif(const string &a, const string &b) {
	vector<int> d;
	for(int i = 0; i < n; i++)
		if(a[i] != b[i])
			d.pb(i);
	return d;
}

int ct[256];

bool try_(const string &x) {
	for(char c : x) ct[c] = 0;
	for(char c : x) ct[c]++;
	bool rep = false;
	for(char c : x) rep = (rep || (ct[c] > 1));
	for(int i = 0; i < k; i++) {
		vector<int> fd = dif(x, s[i]);
		if(fd.empty() && rep) continue;
		if(fd.empty()) return false;
		if(fd.size() != 2) return false;
		int a = fd.front(), b = fd.back();
		if(s[i][a] != x[b] || s[i][b] != x[a]) return false;
	}
	cout << x << endl;
	exit(0);
	return true;
}

void go1(string base, vector<int> ds) {
	for(int x : ds)
		for(int y : ds) {
			if(x >= y) continue;
			swap(base[x], base[y]);
			try_(base);
			swap(base[x], base[y]);
		}
}

void go2(string base, int a, int b) {
	swap(base[a], base[b]);
	try_(base);
	swap(base[a], base[b]);
	for(int i = 0; i < n; i++) {
		if(i == a || i == b || base[i] == base[b] || base[i] != base[a]) continue;
		swap(base[i], base[b]);
		try_(base);
		swap(base[i], base[b]);
		//swap(base[i], base[a]);
		//try_(base);
		//swap(base[i], base[a]);
	}
}

int main() {
	int i, j;
	ios::sync_with_stdio(false);
	cin >> k >> n;
	for(i = 0; i < k; i++)
		cin >> s[i];
	if(k == 1) {
		swap(s[0][0], s[0][1]);
		cout << s[0] << endl;
		return 0;
	} else if(false && k == 2) {
		vector<int> d = dif(s[0], s[1]);
		if(d.size() <= 2) try_(s[0]);
		else if(d.size() >= 3 && d.size() <= 4) go1(s[0], d), go1(s[1], d);
		imp();
	}
	sort(s, s + k);
	k = unique(s, s + k) - s;
	try_(s[0]);
	for(i = 0; i < k; i++) {
		for(j = i + 1; j < k; j++) {
			vector<int> ds = dif(s[i], s[j]);
			if(ds.size() > 4) imp();
			if(ds.size() >= 3) {
				go1(s[i], ds);
				go1(s[j], ds);
				imp();
			}
			if(ds.size() == 2) {
				go2(s[i], ds.front(), ds.back());
				go2(s[j], ds.front(), ds.back());
				imp();
			}
		}
	}
	string b = s[0];
	swap(b[0], b[1]);
	try_(b);
	imp();
}