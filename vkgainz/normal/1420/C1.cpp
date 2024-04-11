#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t; cin >> t;
    while(t--){
        int n,q; cin >> n >> q;
        int a[n];
        for(int i=0;i<n;i++) cin >> a[i];
        set<ll> curr;
        curr.insert(a[0]);
        for(int i=1;i<n;i++){
            auto first = curr.begin();
            auto second = curr.rbegin();
            ll greater = max(a[i]*1LL,a[i]*1LL-*first);
            ll less = min(a[i]*1LL,a[i]*1LL-*second);
            curr.insert(greater);
            curr.insert(less);
        }
        auto it = curr.rbegin();
        cout << (*it) << endl;
    }
}