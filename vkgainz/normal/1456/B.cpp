#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define f first
#define s second
typedef long long ll;
typedef long double ld;
typedef gp_hash_table<int, null_type, hash<int>> ht;
const int MX = 1e5+5;
int main() {
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    if(n>=100) {
        cout << 1 << "\n";
        return 0;
    }
    //do case on overtake
    int ans = 100000000;
    for(int i=0;i<n-1;i++) {
        //after this a[i]>a[i+1]
        vector<int> x, y;
        x.push_back(a[i]);
        for(int j=i-1;j>=0;j--) {
            x.push_back(x[x.size()-1]^a[j]);
        }
        y.push_back(a[i+1]);
        for(int j=i+2;j<n;j++) {
            y.push_back(y[y.size()-1]^a[j]);
        }
        for(int a=0;a<x.size();a++) {
            for(int b=0;b<y.size();b++) {
                if(x[a]>y[b]) ans = min(ans, a+b);
            }
        }
    }
    if(ans==100000000) cout << -1 << "\n";
    else cout << ans << "\n";
}