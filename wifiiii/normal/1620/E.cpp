#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn = 5e5 + 5;
int to[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    vector<int> op(n), x(n), y(n);
    for(int i = 0; i < n; ++i) {
        cin >> op[i] >> x[i];
        if(op[i] == 2) cin >> y[i];
    }
    for(int i = 0; i < maxn; ++i) to[i] = i;
    vector<int> ans;
    for(int i = n - 1; i >= 0; --i) {
        if(op[i] == 2) {
            to[x[i]] = to[y[i]];
        } else {
            ans.push_back(to[x[i]]);
        }
    }
    reverse(ans.begin(), ans.end());
    for(int i : ans) cout << i << " "; cout << '\n';
}