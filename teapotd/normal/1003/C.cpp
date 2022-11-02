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

int n, k;
cin >> n >> k;

Vi prefs = {0};

rep(i, 0, n){
int k; cin >> k;
prefs.pb(prefs.back()+k);
}

double ans = 0;

rep(b, 0, n) rep(e, b+k, n+1) {
double s = prefs[e] - prefs[b];
s /= e-b;
ans = max(ans, s);
}

cout << ans << endl;
    return 0;
}