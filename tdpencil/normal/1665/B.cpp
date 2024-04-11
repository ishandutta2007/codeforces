#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pii;
typedef long long ll;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sz(el) int(el.size())
int const mxN=2e5;
void solve() 
{
    map<int, int> mx;
    int n;
    cin >> n;
    vi a(n);
    for(int &i : a)
        cin >> i, mx[i]++;
    int ans = 0;
    int m = 0;
    for (auto u : mx)
        m=max(m,u.second);
    while(m<n) {
        ans++;
        ans+=min(m,n-m);
        m*=2;
    }
    cout << ans << "\n";

}
int main() {
    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    int test_case;

    cin >> test_case;

    while(test_case--)
    	solve();
}