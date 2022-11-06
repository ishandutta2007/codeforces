#include <bits/stdc++.h>
using namespace std;

#define file "file"
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef complex<double> point;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DEBUG 1
#define dout if(DEBUG) cout

const int MAXN = 2000 + 5;
const int INF = 1e9;

int n, n2;
int p[MAXN];
int pc[MAXN];

void make1() {
    for (int i = 0; i < n2; i += 2){
        swap(pc[i], pc[i + 1]);
    }
}

void make2() {
    for (int i = 0; i < n; i++){
        swap(pc[i], pc[n + i]);
    }
}

bool check() {
    for (int i = 0; i < n2; i++) {
        if (pc[i] != i + 1) return 0;
    }
    return 1;
}

void solve() {
    cin >> n;
    n2 = 2 * n;
    for (int i = 0; i < n2; i++) {
        cin >> p[i];
    }
    // 1, 2, 1, 2
    int lim = n2;
    int ans = INF;

    int cnt = 0;
    for (int i = 0; i < n2; i++) pc[i] = p[i];

    if (check()) {
        cout << 0;
        return;
    }

    for (int i = 0; i < lim; i++){
        make1();
        cnt++;
        if (check()) {
            ans = cnt;
            break;
        }
        make2();
        cnt++;
        if (check()) {
            ans = cnt;
            break;
        }
    }

    for (int i = 0; i < n2; i++) pc[i] = p[i];
    cnt = 0;
    for (int i = 0; i < lim; i++){
        make2();
        cnt++;
        if (check()) {
            ans = min(ans, cnt);
            break;
        }
        make1();
        cnt++;
        if (check()) {
            ans = min(ans, cnt);
            break;
        }
    }

    if (ans == INF) ans = -1;
    cout << ans;
}

int main() {
    #ifdef NASTYA
        assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
    // assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}