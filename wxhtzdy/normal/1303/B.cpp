#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        ll n,g,b;
        cin >> n >> g >> b;
        ll l=(n+1)/2;
        if (n<=g)
            cout << n << "\n";
        else if(l%g==0)
            cout << max(n, (g+b)*(l/g-1)+g) << "\n";
        else
            cout << max(n,(g+b)*(l/g)+l%g) << "\n";
    }
    return 0;
}