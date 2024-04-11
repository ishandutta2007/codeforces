#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    int N; cin >> N;
    ll b = 0, w = 0;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a;
        int cb = a / 2;
        int cw = (a + 1) / 2;
        if (i % 2) swap(cb, cw);
        b += cb, w += cw;
    }
    cout << min(b, w) << '\n';
}