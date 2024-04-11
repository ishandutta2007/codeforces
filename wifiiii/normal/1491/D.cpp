#include<bits/stdc++.h>

typedef long long ll;
using namespace std;

int check(int a, int b) {
    if(a > b) return 0;
    if(a == b) return 1;
    int x = 0, y = 0;
    for(int i = 0; i <= 30; ++i) {
        if(a >> i & 1) ++x;
        if(b >> i & 1) ++y;
        if(y > x) return 0;
    }
    return 1;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        cout << (check(a, b) ? "YES" : "NO") << endl;
    }
}