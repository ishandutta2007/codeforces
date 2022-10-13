#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second

int main() {
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> b(n);
        for(int i=0;i<n;i++) cin >> b[i];
        map<int, vector<int>> m;
        for(int i=0;i<n;i++) {
            m[b[i]].push_back(i);
        }
        bool found = false;
        for(auto &it : m) {
            if((it.s).size()>1 && !found) {
                found = true;
                cout << "YES" << endl;
            }
        }
        if(!found)
        cout << "NO" << endl;
    }
}