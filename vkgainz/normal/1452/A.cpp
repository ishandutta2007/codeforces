#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int x,y; cin >> x >> y;
        if(x==y) cout << x+y << "\n";
        else cout << 2*max(x, y)-1 << "\n";
    }
}