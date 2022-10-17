#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ans = -1, l = -2, r = -2;
        string s;
        cin >> s;
        for(int i = 0; i < n; ++i) {
            int x = 0, y = 0;
            for(int j = i; j < n; ++j) {
                if(s[j] == 'a') ++x;
                else ++y;
                if(x == y) {
                    l = i;
                    r = j;
                }
            }
        }
        cout << l + 1 << " " << r + 1 << endl;
    }
}