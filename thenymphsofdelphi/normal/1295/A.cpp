#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5 + 5, mod = 1e9 + 7, inf = 1e18 + 7;

int n;
int a[N];

signed main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int q = 1;
cin >> q;
while (q--){
    int n; cin >> n;
    if (n & 1){
        cout << 7;
        n -= 3;
    }
    while (n >= 2){
        cout << 1;
        n -= 2;
    }
    cout << endl;
}
}