#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())
 
int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);

int n, q; cin >> n >> q;

array<int, 31> cnt = {};

rep(i, 0, n) {
int k; cin >> k;
int j = 0;
while (k > 1) j++, k /=2;
cnt[j]++;
}

while (q--) {
int k; cin >> k;
int ans = 0;

for (int i = 30; i >= 0; i--) {
int w = min(k >> i, cnt[i]);
k -= w << i;
ans += w;
}

if (k) ans = -1;
cout << ans << char(10);
}

    return 0;
}