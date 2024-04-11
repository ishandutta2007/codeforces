#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int ans = a.size() + b.size();
        for(int i = 0; i < a.size(); ++i) {
            for(int i2 = i; i2 < a.size(); ++i2) {
                for(int j = 0; j < b.size(); ++j) {
                    for(int j2 = j; j2 < b.size(); ++j2) {
                        if(a.substr(i, i2-i+1) == b.substr(j, j2-j+1)) {
                            ans = min(ans, (int)a.size() + (int)b.size() - 2 * (i2-i+1));
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
}