#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int o = 0, e = 0;
        for(int i = 0; i < 2 * n; ++i) {
            int x;
            cin >> x;
            if(x & 1) ++o;
            else ++e;
        }
        if(o == e) cout << "Yes\n";
        else cout << "No\n";
    }
}