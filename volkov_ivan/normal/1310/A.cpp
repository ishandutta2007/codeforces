#include <iostream>
#include <set>
#include <map>
#include <vector>
#define int long long

using namespace std;

multiset <int, greater <int>> s;
map <int, vector <int>> m;
int cur = 0, ans = 0;
const int N = 2e5 + 7, INF = 1e18;
int a[N], t[N];

void add(int val) {
    s.insert(val);
    cur += val;
}

void eras() {
    if (s.empty()) return;
    int x = *s.begin();
    s.erase(s.begin());
    cur -= x;
}


signed main() {
    //freopen("Desktop/input.txt", "r", stdin);
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) m[a[i]].push_back(t[i]);
    for (int i = 0; i < INF; i++) {
        //cout << i << endl;
        if (s.empty()) {
            if (m.empty()) break;
            i = (*m.begin()).first;
        }
        for (int elem : m[i]) add(elem);
        if (m.find(i) != m.end()) m.erase(i);
        eras();
        ans += cur;
    }
    cout << ans << "\n";
    return 0;
}