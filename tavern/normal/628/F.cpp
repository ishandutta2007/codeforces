#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;

const int INF = 1e9 + 7;
const int maxn = 1e4 + 5;

int n, b, q;
int a[maxn], c[maxn];

inline int f(int x, int j){ return (x / 5) + (x % 5 >= j); }
inline int calc(int j, int l, int r){ return f(r, j) - f(l - 1, j); }

int main(){
	scanf("%d%d%d", &n, &b, &q);
	memset(a, -1, sizeof(a));
	FOR(i, 0, q){
		int x, k;
		scanf("%d%d", &x, &k);
		if(~a[x] && a[x] != k){
			puts("unfair");
			return 0;
		}
		a[x] = k;
	}
	if(~a[b] && a[b] != n){
		puts("unfair");
		return 0;
	}
	a[b] = n;
	a[0] = 0;
	FOR(msk, 0, 1 << 5){
		int x, g = 0, lst = 0;
		REP(i, 1, b) if(~a[i]){
			int sub = 0, nin = 0;
			if(a[i] < a[lst]){
				puts("unfair");
				return 0;
			}
			FOR(j, 0, 5){
				if(msk >> j & 1)
					sub += calc(j, lst + 1, i);
				else
					nin += calc(j, lst + 1, i);
			}
			g += min(a[i] - a[lst], sub);
			if(a[i] - a[lst] > i - lst){
				puts("unfair");
				return 0;
			}
			lst = i;
		}
		x = __builtin_popcount(msk) * n / 5;
		if(x > g){
			puts("unfair");
			return 0;
		}
	}
	puts("fair");
	return 0;
}