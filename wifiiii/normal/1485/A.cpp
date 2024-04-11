#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int ans = 1e9;
        for(int i=0;i<=100;++i) {
            int y = b + i;
            if(y == 1) continue;
            int x = a;
            int cnt = 0;
            while(x) {
                x /= y;
                ++cnt;
            }
            ans = min(ans, cnt + i);
        }
        cout << ans << endl;
    }
}