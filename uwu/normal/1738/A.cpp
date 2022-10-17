#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> typ(N);
        for (int i = 0; i < N; ++i){
            cin >> typ[i];
        }
        vector<ll> a, b;
        ll tot = 0;
        for (int i = 0; i < N; ++i){
            int x; cin >> x;
            if (typ[i] == 0) a.push_back(x);
            if (typ[i] == 1) b.push_back(x);
            tot += x;
        }
        sort(a.begin(), a.end(), greater<ll>());
        sort(b.begin(), b.end(), greater<ll>());
        int mn = min(a.size(), b.size());
        if (a.size() == b.size()){
            ll add = 0;
            ll cur = 0;
            for (int i = 0; i < mn; ++i) cur += a[i];
            for (int i = 0; i < mn-1; ++i) cur += b[i];
            add = max(add, cur);
            cur = 0;
            for (int i = 0; i < mn; ++i) cur += b[i];
            for (int i = 0; i < mn-1; ++i) cur += a[i];
            add = max(add, cur);
            tot += add;
        }
        else{
            ll add = 0;
            ll cur = 0;
            for (int i = 0; i < mn; ++i) cur += a[i];
            for (int i = 0; i < mn; ++i) cur += b[i];
            add = max(add, cur);
            cur = 0;
            for (int i = 0; i < mn; ++i) cur += b[i];
            for (int i = 0; i < mn; ++i) cur += a[i];
            add = max(add, cur);
            tot += add;
        }
        cout << tot << '\n';
    }
}