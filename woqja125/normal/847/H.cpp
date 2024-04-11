#include <bits/stdc++.h>

using namespace std;

#define SZ(v) ((int)(v).size())
#define one first
#define two second

const int INF = 0x3f2f1f0f;

const int MAX_N = 1e5 + 100;

typedef long long ll;
typedef pair<int, ll> pil;

int N, Nr[MAX_N];
pil Lv[MAX_N], Rv[MAX_N];
int main() {
	cin >> N; for(int i=1; i<=N; i++) scanf("%d", &Nr[i]);
	Lv[1] = pil(Nr[1], 0ll);
	Rv[N] = pil(Nr[N], 0ll);
	for(int i=2; i<=N; i++) {
		Lv[i].one = max(Lv[i-1].one+1, Nr[i]);
		Lv[i].two = Lv[i-1].two + (Lv[i].one - Nr[i]);
	}
	for(int i=N-1; i>=1; i--) {
		Rv[i].one = max(Rv[i+1].one+1, Nr[i]);
		Rv[i].two = Rv[i+1].two + (Rv[i].one - Nr[i]);
	}

	ll ans = 1ll * INF * INF;
	for(int i=1; i<=N; i++) {
		ll now = Lv[i].two + Rv[i].two - (min(Lv[i].one, Rv[i].one) - Nr[i]);
		ans = min(ans, now);
	}
	printf("%lld\n", ans);
	return 0;
}