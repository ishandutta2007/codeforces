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
    int n, k;
    cin >> n >> k;
    string ans = "";
    for (int i = 0; i < k; i++) {
        ans += (char) ('a' + i);
        for (int j = i + 1; j < k; j++) {
            ans += (char) ('a' + i);
            ans += (char) ('a' + j);
        }
    }
    string tmp = ans;
    while ((int) ans.size() < n) {
        ans += tmp;
    }
    assert((int) ans.size() >= n);
    for (int i = 0; i < n; i++) cout << ans[i];
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    int tt = 1;
    //cin >> tt;
    while (tt--)
        test_case();
}