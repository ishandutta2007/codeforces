#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (int)(x); i < (int)(y); ++i)
#define REP(i, x, y) for(int i = (int)(x); i <= (int)(y); ++i)
#define MP make_pair
#define PB push_back
#define PH push
#define fst first
#define snd second
#define y0 y2226700
#define y1 y2226701
#define y2 y2226702
typedef double lf;
typedef long double Lf;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;

const int maxn = 1e5 + 5;

int n, x;
int a[maxn];

inline void solve(){
	scanf("%d%d", &n, &x);
	int sum = 0;
	FOR(i, 0, n)
		scanf("%d", a + i);
	FOR(i, 0, n){
		if(sum + a[i] == x){
			if(i == n - 1){
				puts("NO");
				return;
			}
			swap(a[i], a[i + 1]);
		}
		sum += a[i];
	}
	puts("YES");
	FOR(i, 0, n)
		printf("%d ", a[i]); puts("");
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}