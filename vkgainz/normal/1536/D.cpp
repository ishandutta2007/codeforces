#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> b(n);
        for(int i = 0; i < n; i++)
            cin >> b[i];
        bool work = true;
        set<int> in;
        in.insert(b[0]);
        for(int i = 1; i < n; i++) {
            if(b[i] == b[i - 1]) {
                continue;
            }
            else {
                if(b[i] < b[i - 1]) {
                    if(b[i - 1] != *in.begin()) {
                        auto it = in.lower_bound(b[i - 1]);
                        --it;
                        if(b[i] < (*it)) work = false;
                    }
                }
                else {
                    if(b[i - 1] != *in.rbegin()) {
                        auto it = in.upper_bound(b[i - 1]);
                        if(b[i] > (*it)) work = false; 
                    }
                }
                in.insert(b[i]);
            }
        }
        if(work) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}