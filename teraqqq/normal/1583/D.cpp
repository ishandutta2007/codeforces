#include <bits/stdc++.h>

using namespace std;
using ll = long  long;
using vi = vector<int>;
using pi = pair<int, int>;

template<class T> bool ckmin(T& a, T b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T& a, T b) { return a < b ? a = b, true : false; }

vector<int> _p;

int ask(vector<int> a) {
    const int n = a.size();

    cout << "?";
    for (int x : a) cout << " " << x;
    cout << endl;

    int res = 0;
    cin >> res;
    return res;

    vector<int> was(228);
    for (int i = 0; i < n; ++i) {
        int s = _p[i] + a[i];
        if (was[s]) {
            res = was[s];
            break;
        }
        was[s] = i + 1;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<int> p(n);

    int got = n - 1;

    for (int i = 1; i < n; ++i) {
        vector<int> a(n, 1);
        a.back() = i + 1;

        int k = ask(a);
        if (!k) break;
        p[k-1] = i;
        --got;
    }

    for (int i = 1; i < n && got != 0; ++i) {
        vector<int> a(n, i+1);
        a.back() = 1;

        int k = ask(a);
        if (!k) break;
        p[k-1] = -i;
        --got;
    }

    int dx = *min_element(p.begin(), p.end());
    for (int& x : p) x -= dx - 1;

    cout << "!";
    for (int x : p) cout << " " << x;
    cout << endl;
}