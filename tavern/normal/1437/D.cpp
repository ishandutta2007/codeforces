#include<bits/stdc++.h>

using namespace std;

#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
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

const int maxn = 2e5 + 5;

int n, ans;
int a[maxn], cnt[maxn], len[maxn];

inline void solve(){
	scanf("%d", &n);
	FOR(i, 0, n)
		scanf("%d", a + i);
	ans = 0;
	cnt[0] = len[0] = 1, ans = 1;
	for(int i = 1, j; i < n; ){
		cnt[ans] = len[ans] = 0;
		for(j = i; j < n && cnt[ans] + (j == i || a[j] < a[j - 1]) <= len[ans - 1]; ++j){
			cnt[ans] += (j == i || a[j] < a[j - 1]);
			++len[ans];
		}
		++ans;
		i = j;
	}
	if(!len[ans - 1])
		--ans;
	printf("%d\n", ans - 1);
	return;
}

int main(){
	int T;
	for(scanf("%d", &T); T--; solve());
	return 0;
}