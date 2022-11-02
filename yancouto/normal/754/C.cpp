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
#	define debug(args...) {}
#else
#	define debug(args...) fprintf(stderr, args)
#endif

template<class num> inline void rd(num &x) {
	char c;
	while(isspace(c = getchar()));
	bool neg = false;
	if(!isdigit(c)) neg = (c == '-'), x = 0;
	else x = c - '0';
	while(isdigit(c = getchar()))
		x = (x << 3) + (x << 1) + c - '0';
	if(neg) x = -x;
}

int n, m;

vector<int> canv[112];
int ok[112], us[112];
int memo[112][112];
bool go(int i, int p) {
	if(i == m) return true;
	int &r = memo[i][p];
	if(r != -1) return r;
	if(ok[i]) return (r = ((p != us[i]) && go(i + 1, us[i])));
	r = 0;
	for(int x : canv[i])
		if(x != p)
			r = r || go(i + 1, x);
	return r;
}

char name[112][112], ch[112][512];
set<int> can[112];
map<string, int> mp;
char l[512];

int main() {
	int i, j, k, t;
	rd(t);
	while(t--) {
		mp.clear();
		memset(memo, -1, sizeof memo);
		rd(n);
		for(i = 0; i < n; i++) scanf(" %s", name[i]), mp[name[i]] = i;
		rd(m); scanf(" ");
		for(i = 0; i < m; i++) {
			fgets(l, sizeof l, stdin);
			l[strlen(l) + 1] = 0;
			can[i].clear();
			for(j = 0; j < n; j++) can[i].insert(j);
			for(j = 0; l[j] != ':'; j++);
			l[j] = 0;
			strcpy(ch[i], l + j + 1);
			if(l[0] != '?') ok[i] = 1, us[i] = mp[l];
			else {
				ok[i] = 0;
				j++;
				while(l[j]) {
					for(; l[j] && !isalnum(l[j]); j++);
					if(!l[j]) break;
					for(k = j; isalnum(l[k]); k++);
					l[k] = 0;
					if(mp.count(l + j)) can[i].erase(mp[l + j]);
					j = k + 1;
				}
				canv[i].clear();
				for(int x : can[i]) canv[i].pb(x);
			}
		}
		if(!go(0, n)) { puts("Impossible"); continue; }
		int p = n;
		for(i = 0; i < m; i++) {
			if(ok[i] == 1) p = us[i];
			else {
				for(int x : canv[i])
					if(x != p && go(i + 1, x)) {
						p = x;
						break;
					}
			}
			printf("%s:%s", name[p], ch[i]);
		}
	}
}