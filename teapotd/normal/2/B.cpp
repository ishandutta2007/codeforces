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

constexpr int KEK = 1001;
int two[KEK][KEK];
int five[KEK][KEK];
bool dir2[KEK][KEK];
bool dir5[KEK][KEK];

int main() {
    cin.sync_with_stdio(0);
    int n; cin >> n;

    int zeroX = -1;

    rep(i, 0, n) rep(j, 0, n) {
        int k; cin >> k;
        if (k == 0) {
            zeroX = i;
            two[i][j]++;
            five[i][j]++;
            continue;
        }
        while (k%2 == 0) {
            two[i][j]++;
            k /= 2;
        }
        while (k%5 == 0) {
            five[i][j]++;
            k /= 5;
        }
    }

    for (int i = n-1; i >= 0; i--) {
        for (int j = n-1; j >= 0; j--) {
            if (i == n-1 && j == n-1) continue;

            pair<int, bool> alt2 = {INT_MAX, 0}, alt5 = {INT_MAX, 0};

            if (i < n-1) {
                alt2 = min(alt2, make_pair(two[i+1][j], false));
                alt5 = min(alt5, make_pair(five[i+1][j], false));
            }
            if (j < n-1) {
                alt2 = min(alt2, make_pair(two[i][j+1], true));
                alt5 = min(alt5, make_pair(five[i][j+1], true));
            }

            two[i][j] += alt2.x;
            five[i][j] += alt5.x;
            dir2[i][j] = alt2.y;
            dir5[i][j] = alt5.y;
        }
    }

    int ans = min(two[0][0], five[0][0]);

    if (ans > 0 && zeroX != -1) {
        cout << "1\n";
        rep(i, 0, zeroX) cout << 'D';
        rep(i, 0, n-1) cout << 'R';
        rep(i, zeroX, n-1) cout << 'D';
        cout << '\n';
        return 0;
    }

    cout << ans << '\n';
    int x = 0, y = 0;

    while (x != n-1 || y != n-1) {
        if (five[0][0] < two[0][0] ? dir5[x][y] : dir2[x][y]) {
            cout << 'R';
            y++;
        } else {
            cout << 'D';
            x++;
        }
    }

    cout << '\n';
    return 0;
}