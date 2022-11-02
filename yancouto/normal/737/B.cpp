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

template<class num> inline void read(num &x) {
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
const int N = 212345;
int v[N];
char s[N];

int main() {
	int i, j, vn = 0, a, b, k;
	read(n); read(a); read(b); read(k);
	scanf("%s", s);
	int cur = 0;
	for(i = 0; i < n; i++) {
		if(s[i] == '1') v[vn++] = cur, cur = 0;
		else cur++;
	}
	v[vn++] = cur;
	int pos = 0;
	for(i = 0; i < vn; i++) {
		pos += (v[i] / b);
	}
	assert(pos >= a);
	printf("%d\n", pos - a + 1);
	int left = pos - a + 1;
	cur = 0;
	for(i = 0; i < n; i++) {
		if(s[i] == '1') {
			pos = i - b;
			while(cur >= b && left) left--, cur -= b, printf("%d ", pos+1), pos -= b;
			cur = 0;
		}
		else cur++;
	}
	pos = n - b;
	while(cur >= b && left) left--, cur -= b, printf("%d ", pos+1), pos -= b;
	cur = 0;
	putchar('\n');
}