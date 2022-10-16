#include <bits/stdc++.h>

#define F first
#define S second
#define pb push_back
#define rsz resize

using namespace std;
using vi = vector<int>;
using ll = long long;
using pi = pair<int, int>;
using vpi = vector<pi>;
using vl = vector<ll>;

const ll LINF = 1e18;
const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, k; cin >> n >> k;
    map<int, int> kek;
    for(int i = 1; i <= k+1; ++i) {
        cout << "?";
        for(int j = 1; j <= k+1; ++j)
            if(i != j) cout << ' ' << j;
        cout << endl;

        int a, b; cin >> a >> b;
        kek[b]++;
    }

    int m = 0, t = INF;
    for(pi x : kek) if(t > x.F) m = x.S;
    cout << "! " << m << endl;
}