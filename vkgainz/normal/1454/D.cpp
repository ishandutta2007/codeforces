#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define f first
#define s second
const int MX = 1e6+5;

int main() {
    int t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        ll temp = n;
        vector<pair<int, ll>> f;
        for(int i=2;i*1LL*i<=n;i++) {
            if(n%i==0) {
                int x = 0;
                while(n%i==0) {
                    n/=i;
                    ++x;
                }
                f.push_back({x, i});
            }
        }
        if(n>1) f.push_back({1, n});
        sort(f.begin(), f.end());
        int k = f[f.size()-1].f;
        vector<ll> ans; 
        ll prod = 1;
        for(int i=0;i<k-1;i++) {
            ans.push_back(f[f.size()-1].s);
            prod*=f[f.size()-1].s;
        }
        ans.push_back(temp/prod);
        cout << k << "\n";
        for(auto &it : ans) cout << it << " ";
        cout << "\n";
    }
}