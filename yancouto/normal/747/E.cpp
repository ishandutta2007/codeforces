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

char s[1123456];
vector<string> d[1123456];

int nx_sep(int i) {
	while(s[i] && s[i] != ',') i++;
	return i;
}

int mxd = 0;

int read(int i, int dep) {
	mxd = max(mxd, 1 + dep);
	int j = nx_sep(i);
	s[j] = 0;
	d[dep].pb(string(s + i));
	int k = nx_sep(j + 1);
	s[k++] = 0;
	int ch = atoi(s + j + 1);
	while(ch)
		k = read(k, dep + 1), ch--;
	return k;
}

int n;

int main() {
	int i, j;
	scanf("%s", s);
	n = strlen(s);
	int cur = 0;
	while(cur < n)
		cur = read(cur, 0);
	printf("%d\n", mxd);
	for(i = 0; i < mxd; i++) {
		for(string &s : d[i])
			printf("%s ", s.c_str());
		putchar('\n');
	}
}