#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// w % a == 0 or w % a == 1 or w % a == 2
// l % a == 0 or l % a == 1 or l % a == 2
int check(int w, int l, int a) {
    if(w % a == 0 && (l - 2) % a == 0) return 1;
    if((w - 1) % a == 0 && (l - 1) % a == 0) return 1;
    if((w - 1) % a == 0 && (l - 2) % a == 0 && l % a == 0) return 1;
    if((w - 2) % a == 0 && l % a == 0) return 1;
    if(w % a == 0 && (w - 2) % a == 0 && (l - 1) % a == 0) return 1;
    return 0;
}
vector<int> f(int x) {
    vector<int> d;
    for(int i = 1; i * i <= x; ++i) {
        if(x % i == 0) {
            d.push_back(i);
            if(i * i != x) d.push_back(x / i);
        }
    }
    return d;
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int w, l;
        cin >> w >> l;
        vector<int> a;
        for(int i : f(w)) {
            a.push_back(i);
        }
        for(int i : f(w - 1)) {
            a.push_back(i);
        }
        for(int i : f(w - 2)) {
            a.push_back(i);
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        vector<int> ans;
        for(int i : a) {
            if(check(w, l, i)) ans.push_back(i);
        }
        cout << ans.size() << ' ';
        for(int i : ans) cout << i << ' '; cout << '\n';
    }
}