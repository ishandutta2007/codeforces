#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i = (b); i < (e); i++)
#define each(a,x) for(auto&a:(x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

int main() {
    cin.sync_with_stdio(0);
    int a, b, c; cin >> a >> b >> c;

    rep(ab, 0, a+1) {
        int ac = a-ab;
        int bc = b-ab, cb = c-ac;

        if (bc == cb && ac >= 0 && bc >= 0 && cb >= 0) {
            cout << ab << ' ' << bc << ' ' << ac << '\n';
            return 0;
        }
    }

    cout << "Impossible\n";
    return 0;
}