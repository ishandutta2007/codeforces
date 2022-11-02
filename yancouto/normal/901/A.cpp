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

const int N = 312345;
int p[N], p2[N], a[N];

int main() {
	int i, h;
	rd(h);
	for(i = 0; i <= h; i++) rd(a[i]);
	int last = 1;
	bool unique = true;
	int cur = 1;
	for(i = 1; i <= h; i++) {
		for(int j = 0; j < a[i]; j++) {
			cur++;
			p[cur] = p2[cur] = last;
		}
		last = cur;
		if(unique && a[i] > 1 && a[i + 1] > 1) {
			unique = false;
			i++;
			for(int j = 0; j < a[i] - 1; j++) {
				cur++;
				p[cur] = p2[cur] = last;
			}
			cur++;
			p[cur] = last;
			p2[cur] = last - 1;
			last = cur;
		}
	}
	if(unique)
		puts("perfect");
	else {
		puts("ambiguous");
		for(i = 1; i <= cur; i++)
			printf("%d ", p[i]);
		putchar('\n');
		for(i = 1; i <= cur; i++)
			printf("%d ", p2[i]);
		putchar('\n');
	}
}