#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

string a , b , c , ans;

int main(void) {
    cin >> a >> b;
    ans = ""; ans += a[0]; ans += b[0];
    for(int i = 0;i < (int) a.length();++ i) {
        for(int j = 0;j < (int) b.length();++ j) {
            c = "";
            for(int p = 0;p <= i;++ p) c += a[p];
            for(int p = 0;p <= j;++ p) c += b[p];
            ans = min(ans , c);
        }
    }
    cout << ans;
}