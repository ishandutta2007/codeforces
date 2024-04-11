#include<bits/stdc++.h>
using namespace std;


int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<int> o, e;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i % 2) e.push_back(a[i]);
            else o.push_back(a[i]);
        }
        sort(o.begin(), o.end());
        sort(e.begin(), e.end());
        reverse(o.begin(), o.end());
        reverse(e.begin(), e.end());
        vector<int> s;
        for(int i = 0; i < n / 2; i++) {
            s.push_back(o.back());
            s.push_back(e.back());
            o.pop_back(), e.pop_back();
        }
        if(!o.empty())
            s.push_back(o.back());
        bool work = true;
        for(int i = 0; i < n - 1; i++) 
            work &= s[i] <= s[i + 1];
        if(work) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}