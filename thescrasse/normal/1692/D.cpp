#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;
ll x;
string s;
set<ll> st;

bool pal(ll a, ll b) {
    return (a % 10 == b / 10 && a / 10 == b % 10);
}

array<ll, 2> dc(ll x) {
    x %= 1440;
    return {x / 60, x % 60};
}

ll nc(ll a, ll b) {
    return (60 * a + b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    // perch mettete ancora problemi con l'orologio???

    cin >> t;
    while (t--) {
        cin >> s >> k;
        a = 10 * ((ll)s[0] - '0') + ((ll)s[1] - '0');
        b = 10 * ((ll)s[3] - '0') + ((ll)s[4] - '0');
        x = nc(a, b);

        st.clear();
        for (i = 1; i <= 1450; i++) {
            if (pal(dc(x)[0], dc(x)[1])) st.insert(x);
            x = (x + k) % 1440;
        }

        cout << st.size() << nl;
    }

    return 0;
}