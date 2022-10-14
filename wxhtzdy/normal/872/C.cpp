#include <bits/stdc++.h>

using namespace std;

int solve() {
    int n;
    cin >> n;
    if(n%4 == 0) return n/4;
    if(n%4 == 1){
        if(n < 9) return -1;
        return (n-9)/4+1;
    }
    if(n%4 == 2){
        if(n < 6) return -1;
        return (n-6)/4+1;
    }
    if(n%4 == 3){
        if(n < 15) return -1;
        return (n-15)/4+2;
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        cout << solve() << "\n";
    }
    return 0;
}