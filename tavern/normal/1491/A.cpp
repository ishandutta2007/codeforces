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

const int maxn = 1e5 + 5;

int n, q;
int a[maxn], cnt[2];

int main(){
	scanf("%d%d", &n, &q);
	FOR(i, 0, n)
		scanf("%d", a + i), ++cnt[a[i]];
		
	FOR(i, 0, q){
		int t, x; scanf("%d%d", &t, &x);
		if(t == 1){
			--x;
			--cnt[a[x]];
			a[x] ^= 1;
			++cnt[a[x]];
		}
		else{
			printf("%d\n", cnt[1] >= x);
		}
	}
	return 0;
}