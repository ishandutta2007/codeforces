#include <bits/stdc++.h>
using namespace std;

const int mxN=2e5;
int n, m, d, ai, a1, x, a2[mxN];
set<pair<int, int>> s;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> d;
    for(int i=0; i<n; ++i) {
        cin >> ai;
        s.insert({ai, i});
    }
    while(s.size()) {
        ++a1;
        auto it=s.begin();
        while(it!=s.end()) {
            a2[it->second]=a1;
            x=it->first;
            s.erase(it);
            it=s.lower_bound({x+d+1, 0});
        }
    }
    cout << a1 << "\n";
    for(int i=0; i<n; ++i)
        cout << a2[i] << " ";
}