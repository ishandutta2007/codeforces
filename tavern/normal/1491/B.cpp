#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define PB push_back
#define MP make_pair
#define PH push
#define fst first
#define snd second
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double Lf;
typedef pair<int, int> pii;

const int maxn = 105;

int n, s, t;
int a[maxn];

inline void solve(){
	scanf("%d%d%d", &n, &s, &t);
	bool f1 = true, f2 = true;
	FOR(i, 0, n){
		scanf("%d", a + i);
		if(i){
			f1 &= (abs(a[i] - a[i - 1]) <= 1);
			f2 &= (a[i] == a[0]);
		}
	}
	
	if(f1 && f2)
		printf("%d\n", t + min(s, t));
	else if(f1)
		printf("%d\n", min(s, t));
	else
		puts("0");
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}