#include <bits/stdc++.h>

using namespace std;


typedef long long ll;

#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back



void solve() {
    int n; cin >> n;
    vector<int> a(n);

    for(int &i : a)
        cin >> i;
    
    if(is_sorted(all(a))) {
        cout << 0 << "\n";
        return;
    }
    int f = 0, s = n - 1;
    while(s >= 0 && a[s] == s+1) s--;
    while(f < s && a[f] == f + 1) f++;
    bool fits = false;
    for(int i = f; i <= s; i++) {
        if(a[i] == i + 1) {
            fits = true;
        }
    }

    if(fits)
        cout << 2 << "\n";
    else
        cout << 1 << "\n";
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t = 1, i = 1;
	cin >> t;
	while(t--) {
		// printf("Case #%d: ", i)
		solve();
		i++;
	}
}