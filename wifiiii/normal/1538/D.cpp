#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b, k;
        cin >> a >> b >> k;
        if(k == 1) {
            if(a == b) {
                cout << "No\n";
            } else if(a % b == 0 || b % a == 0) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
            continue;
        }
        int cnt = 0;
        for(int i = 2; i * i <= a; ++i) {
            while(a % i == 0) cnt++, a /= i;
        }
        if(a > 1) ++cnt;
        for(int i = 2; i * i <= b; ++i) {
            while(b % i == 0) cnt++, b /= i;
        }
        if(b > 1) ++cnt;
        if(k > cnt) cout << "No\n";
        else cout << "Yes\n";
    }
}