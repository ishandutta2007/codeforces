#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        set<int> s;
        for(int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            x = abs(x);
            if(s.count(x)) {
                s.insert(-x);
            } else {
                s.insert(x);
            }
        }
        cout << s.size() << '\n';
    }
}