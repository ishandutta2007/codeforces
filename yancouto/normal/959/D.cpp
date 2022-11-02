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

const int N = 3123456;

vector<int> ps[N];

int mrk[N];
bool isp[N];

int a[N];

int main() {
	int i, j;
	for(i = 2; i < N; i++)
		if(ps[i].empty()) {
			isp[i] = 1;
			for(j = i; j < N; j += i)
				ps[j].pb(i);
		}
	rd(n);
	for(i = 0; i < n; i++)
		rd(a[i]);
	for(i = 0; i < n; i++) {
		bool bad = false;
		for(int p : ps[a[i]])
			if(mrk[p])
				bad = 1;
		if(bad) {
			for(int j = a[i] + 1; ; j++) {
				bool b = false;
				for(int p : ps[j])
					if(mrk[p])
						b = 1;
				if(!b) {
					for(int p : ps[j])
						mrk[p] = 1;
					printf("%d ", j);
					break;
				}
			}
			break;
		} else {
			for(int p : ps[a[i]])
				mrk[p] = 1;
			printf("%d ", a[i]);
		}
	}
	j = 2;
	for(i++; i < n; i++) {
		while(!isp[j] || mrk[j])
			j++;
		assert(j < N);
		printf("%d ", j++);
	}
	putchar('\n');
}