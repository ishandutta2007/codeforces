#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int a, b, c, r; cin >> a >> b >> c >> r;
        if (a > b) swap(a, b);
        int cl = c - r, cr = c + r;
        if (a > cr || b < cl){
            cout << b - a << '\n';
        }
        else{
            int sect = min(b, cr) - max(a, cl);
            cout << b - a - sect << '\n';
        }
    }
}