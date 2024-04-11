#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    auto ask = [](int a, int b, int c) {
        cout << "? " << a << ' ' << b << ' ' << c << endl;
        int result;
        cin >> result;
        if (result == -1) {
            exit(0);
        }
        return result;
    };
    auto guess = [](int a, int b) {
        cout << "! " << a << ' ' << b << endl;
    };
    while (T--) {
        int n;
        cin >> n;
        int id1 = 1, id2 = 2;
        int cur = 3;
        while (cur + 1 <= n) {
            vector<pair<int, int>> kek = {
                    {ask(id1, id2, cur), cur + 1},
                    {ask(id1, id2, cur + 1), cur},
                    {ask(id2, cur, cur + 1), id1},
                    {ask(id1, cur, cur + 1), id2}};
            sort(all(kek));
            id1 = kek[0].second;
            id2 = kek[1].second;
            cur += 2;
        }
        if (cur == n) {
            int cur2 = 1;
            while (cur2 == id1 || cur2 == id2) {
                cur2++;
            }
            vector<pair<int, int>> kek = {
                    {ask(id1, id2, cur), cur2},
                    {ask(id1, id2, cur2), cur},
                    {ask(id2, cur, cur2), id1},
                    {ask(id1, cur, cur2), id2}};
            sort(all(kek));
            id1 = kek[0].second;
            id2 = kek[1].second;
        }
        guess(id1, id2);
    }
}