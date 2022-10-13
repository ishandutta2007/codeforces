#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first

void solve() {
    int n; cin >> n;
    ll W; cin >> W;
    int w[n];
    for(int i=0;i<n;i++) cin >> w[i];
    ll sum = 0;
    for(int i=0;i<n;i++) {
        if(w[i]<=W&&w[i]>=((W+1)/2)) {
            cout << 1 << "\n" << (i+1) << "\n";
            return;
        }
        sum+=w[i];
    }
    if(sum<((W+1)/2)) {
        cout << -1 << "\n";
        return;
    }
    ll x = 0;
    vector<int> in;
    for(int i=0;i<n;i++) {
        if(w[i]<((W+1)/2)) {
            x+=w[i];
            in.push_back(i);
            if(x>=((W+1)/2)) {
                cout << in.size() << "\n";
                for(auto &it : in) cout << it+1 << " ";
                cout << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
    return;
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}