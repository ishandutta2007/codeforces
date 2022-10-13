#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define s second
#define f first
const int MX = 5e5+5;

int main() {
    int t; cin >> t;
    while(t--) {
        int n, m, r, c; cin >> n >> m >> r >> c;
        cout << max(n-r, r-1)+max(m-c, c-1) << "\n";
    }
}