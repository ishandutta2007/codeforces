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

int n;
const int N = 51234;
int p[N];
string s[N];

int main() {
	int i, j;
	rd(n);
	for(i = 0; i < n; i++) cin >> s[i];
	for(i = 0; i < n; i++) p[i] = i;
	sort(p, p + n, [](int i, int j) { return (s[i] + s[j]) < (s[j] + s[i]); });
	for(i = 0; i < n; i++) printf("%s", s[p[i]].c_str());
	putchar('\n');
}