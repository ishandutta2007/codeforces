#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> s;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            if(!s.empty() && *prev(s.end()) > x) {
                int p = *prev(s.end());
                while(!s.empty() && *prev(s.end()) > x) {
                    s.erase(prev(s.end()));
                }
                s.insert(p);
            } else {
                s.insert(x);
            }
        }
        cout << s.size() << '\n';
    }
}