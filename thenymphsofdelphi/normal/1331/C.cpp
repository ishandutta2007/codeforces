#include <bits/stdc++.h>
using namespace std;
 
int n;
 
int main() {
    cin >> n;
    int ans = (((n>>5)&1)<<5) + (((n>>4)&1)<<0) + (((n>>3)&1)<<2) + (((n>>2)&1)<<3) + (((n>>1)&1)<<1) + (((n>>0)&1)<<4);
    cout << ans;
}