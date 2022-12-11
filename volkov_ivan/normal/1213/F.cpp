#include <iostream>
#include <cstring>

using namespace std;

const int MAX_N = 2e5 + 7;
bool vis1[MAX_N], vis2[MAX_N];

int count(int pos) {
    if (vis1[pos] == vis2[pos]) return 0;
    return 1;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    string s = "";
    cin >> n >> k;
    int p1[n], p2[n];
    for (int i = 0; i < n; i++) cin >> p1[i];
    for (int i = 0; i < n; i++) cin >> p2[i];
    for (int i = 0; i < n; i++) s += "a";
    int cnt = 0;
    memset(vis1, 0, sizeof(vis1));
    memset(vis2, 0, sizeof(vis2));
    int cur = 1;
    bool used = 0;
    for (int i = 0; i < n; i++) {
        if (!used) used = 1;
        s[p1[i] - 1] = 'a' + cur - 1;
        cnt -= count(p1[i]);
        cnt -= count(p2[i]);
        vis1[p1[i]] = vis2[p2[i]] = 1;
        cnt += count(p1[i]);
        cnt += count(p2[i]);
        if (cnt == 0 && cur < k) cur++, used = 0;
    }
    if (cur != k || !used) {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    cout << s << endl;
    return 0;
}