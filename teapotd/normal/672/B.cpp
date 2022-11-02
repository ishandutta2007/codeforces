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

    int n;
    string s;
    cin >> n >> s;

    if (n > 26) {
        cout << -1 << endl;
        return 0;
    }

    bool seen[26] = {0};
    int ans = 0;

    each(c, s) {
        int i = c-'a';
        if (seen[i]) ans++;
        seen[i] = 1;
    }

    cout << ans << endl;
    return 0;
}