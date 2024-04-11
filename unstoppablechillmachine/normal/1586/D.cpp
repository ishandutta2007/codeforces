#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;

    auto ask = [](vector<int> &a) {
        cout << "? ";
        for (auto it : a) {
            cout << it << ' ';
        }
        cout << endl;
        int result;
        cin >> result;
        return result;
    };

    auto answer = [](vector<int> &a) {
        cout << "! ";
        for (auto it : a) {
            cout << it << ' ';
        }
        cout << endl;
    };

    vector<int> a(n, 1);
    int lst = n;
    for (int i = 2; i <= n; i++) {
        a.back() = i;
        lst -= (ask(a) != 0);
    }

    vector<int> perm(n);
    perm.back() = lst;

    for (int i = 1; i <= n; i++) {
        if (i == lst) {
            continue;
        }
        if (lst > i) {
            fill(all(a), lst - i + 1);
            a.back() = 1;
        } else {
            fill(all(a), 1);
            a.back() = i - lst + 1;
        }
        int pos = ask(a);
        assert(pos != 0);
        perm[pos - 1] = i;
    }
    answer(perm);
}