// WA
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
const int N = 1123456;

int nx[26][N];
int k;
int us[256];
ll val[30], cnt[N];
char s[N];
ll all;
int g[N];

int main() {
	int i, j, n;
	scanf("%d %d", &n, &k);
	scanf("%s", s);
	int m = strlen(s);
	for(i = 0; i < k; i++) nx[i][m - 1] = -1;
	for(i = m - 2; i >= 0; i--) {
		nx[s[i + 1] - 'a'][i] = i + 1;
		for(j = 0; j < k; j++)
			if(j != (s[i + 1] - 'a'))
				nx[j][i] = nx[j][i + 1];
	}
	for(i = 0; s[i]; i++)
		if(!us[s[i]]) {
			cnt[i]++;
			us[s[i]] = 1;
		}
	for(i = 0; s[i]; i++)
		for(j = 0; j < k; j++)
			if(nx[j][i] != -1)
				cnt[nx[j][i]] = mod(cnt[nx[j][i]] + cnt[i]);
	for(i = m - 2; i >= 0; i--)
		cnt[i] = mod(cnt[i] + cnt[i + 1]);
	all = mod(cnt[0] + 1);
	deque<int> p;
	for(j = 0; j < k; j++) {
		for(i = m - 1; i >= 0 && nx[j][i] == -1; i--);
		i++;
		val[j] = cnt[i];
		g[j] = i;
		if(!us[j + 'a']) val[j] = mod(val[j] + 1), g[j]--;
		p.pb(j);
	}
	sort(p.begin(), p.end(), [](int i, int j) { return g[i] < g[j]; });
	for(i = 0; i < n; i++) {
		int mx = p.front();
		p.pop_front();
		p.pb(mx);
		all = mod(all + val[mx]);
		for(j = 0; j < k; j++)
			if(j != mx)
				val[j] = mod(val[j] + val[mx]);
	}
	printf("%I64d\n", all);
}