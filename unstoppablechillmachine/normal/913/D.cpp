#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define sec second
#define mk make_pair
#define pb push_back
#define int ll
#define all(x) x.begin(), x.end()

const int INF = 1e9 + 10;

multiset<pair<int, int> > st, was;

signed main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, mx;
    cin >> n >> mx;
    vector<vector<pair<int, int> > > arr(n + 1);
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        arr[a].pb(mk(b, i));
    }
    int sum = 0, ans = 0, num = 0;
    for (int i = n; i >= 1; i--) {
        for (auto it : arr[i]) {
            sum += it.f;
            st.insert(it);
        }
        while (st.size() > i || sum > mx) {
            auto it = --st.end();
            was.insert(mk(it->f, it->sec));
            sum -= it->f;
            st.erase(it);
        }
        while (st.size() < i && !was.empty() && sum + was.begin()->f <= mx) {
            sum += was.begin()->f;
            st.insert(*was.begin());
            was.erase(was.begin());
        }
        if (st.size() > ans) {
            ans = st.size();
            num = i;
        }
    }
    sum = 0;
    st.clear();
    was.clear();
    for (int i = n; i >= 1; i--) {
        for (auto it : arr[i]) {
            sum += it.f;
            st.insert(it);
        }
        while (st.size() > i || sum > mx) {
            auto it = --st.end();
            was.insert(mk(it->f, it->sec));
            sum -= it->f;
            st.erase(it);
        }
        while (st.size() < i && !was.empty() && sum + was.begin()->f <= mx) {
            sum += was.begin()->f;
            st.insert(*was.begin());
            was.erase(was.begin());
        }
        if (i == num) {
            cout << st.size() << endl << st.size() << endl;
            for (auto it : st) {
                cout << it.sec << ' ';
            }
            exit(0);
        }
    }
    cout << 0 << endl << 0;
    return 0;
}