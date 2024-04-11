#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);

    int n; cin >> n;
    map<ll, int> cnt;
    ll sum = 0;

    rep(i, 0, n) {
        int k; cin >> k;
        sum += k;
        cnt[sum]++;
    }

    int best = 0;
    each(e, cnt) best = max(best, e.y);
    cout << n-best << endl;
    return 0;
}