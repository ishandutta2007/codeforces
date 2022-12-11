#include <iostream>
#include <algorithm>
#include <vector>
#define int long long

using namespace std;

const int N = 1e3 + 7;
int s[N];
bool lft[N];
int maxi, res = 0;

bool cmp(int a, int b) {
    if (a == b) return 0;
    if (a == maxi) return !lft[b];
    if (b == maxi) return lft[a];
    if (lft[a] && !lft[b]) return 1;
    if (lft[b] && !lft[a]) return 0;
    if (lft[a] && lft[b]) {
        return (s[a] < s[b]);
    }
    return (s[a] > s[b]);
}

signed main() {
    int n;
    cin >> n;
    int nxt = 2;
    for (int i = 3; i <= n; i++) {
        cout << "2 1 " << nxt << ' ' << i << endl;
        int x;
        cin >> x;
        if (x == -1) nxt = i;
    }
    vector <int> other;
    for (int i = 2; i <= n; i++) {
        if (i == nxt) continue;
        cout << "1 1 "  << nxt << ' ' << i << endl;
        other.push_back(i);
        cin >> s[i];
        if (s[i] > res) {
            res = s[i];
            maxi = i;
        }
    }
    for (int i = 2; i <= n; i++) {
        if (i == nxt || i == maxi) continue;
        cout << "2 1 " << i << ' ' << maxi << endl;
        int x;
        cin >> x;
        if (x == 1) lft[i] = 1;
        else lft[i] = 0;
    }
    sort(other.begin(), other.end(), cmp);
    cout << "0 1 ";
    cout << nxt << ' ';
    for (int elem : other) cout << elem << ' ';
    cout << endl;
}