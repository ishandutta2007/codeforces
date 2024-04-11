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

int n;

vector<int> v[30];
int qt[30];

int main() {
	int i, j;
	string s;
	cin >> s;
	n = s.size();
	for(i = 0; i < n; i++)
		v[s[i] - 'a'].pb(i);
	double ans = 0;
	for(i = 0; i < 26; i++) {
		if(v[i].empty()) continue;
		if(v[i].size() == 1) { ans += 1; continue; }
		if(v[i].size() == 2) {
			string t1 = s, t2 = s;
			rotate(t1.begin(), t1.begin() + v[i][0], t1.end());
			rotate(t2.begin(), t2.begin() + v[i][1], t2.end());
			if(t1 != t2) ans += 2;
			continue;
		}
		int mx = 0;
		for(j = 0; j < n; j++) {
			for(int k : v[i])
				qt[s[(k + j) % n] - 'a']++;
			int cur = 0;
			int k;
			for(k = 0; k < 26; k++)
				if(qt[k] == 1)
					cur++;
			mx = max(mx, cur);
			for(int k : v[i])
				qt[s[(k + j) % n] - 'a']--;
		}
		ans += mx;
	}
	printf("%.15f\n", ans / n);
}