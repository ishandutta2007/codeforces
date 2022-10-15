#include "bits/stdc++.h"

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define debug(x) cerr << #x << " == " << (x) << '\n';
#define all(X) begin(X), end(X)
#define size(X) (int)std::size(X)

using ll = long long;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;

int main()
{ _
    int hpy, atky, defy; cin >> hpy >> atky >> defy;

    int hpm, atkm, defm; cin >> hpm >> atkm >> defm;

    int h, a, d; cin >> h >> a >> d;

    int ans = INF;

    int add = a * max(0, defm + 1 - atky);

    atky = max(atky, defm + 1);

    atkm = max(atkm, defy);

    for (int def = defy; def <= atkm; ++def)
        for (int atk = atky; atk <= max(atky, defm + hpm); ++atk)
        {
            int cur = a * (atk - atky) + d * (def - defy);

            int damage = atk - defm;

            int need = (hpm + damage - 1) / damage;

            int cure = max(0, need * max(0, atkm - def) - (hpy - 1));

            cur += cure * h;

            ans = min(ans, cur);
        }

    ans += add;

    cout << ans << endl;

    exit(0);
}