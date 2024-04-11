#include <bits/stdc++.h>
using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

void test_case() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    const int MAX = 55;
    vector<int> col[MAX];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (col[a[i]].empty()) {
            col[a[i]].pb(i);
        }
    }
    while (q--) {
        int t;
        cin >> t;
        cout << col[t][0] + 1 << " ";
        for (int j = 0; j < MAX; j++) {
            if (col[j].empty()) continue;
            if (col[j][0] < col[t][0]) {
                col[j][0]++;
            }
        }
        col[t][0] = 0;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
        test_case();
}