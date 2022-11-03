#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef long long ll;

#define FOR(i, s, e) for (int (i) = (s); (i) < (e); (i)++)

int main() {
    int N; cin >> N;
    int a[110]; FOR(i, 0, N) cin >> a[i];

    int x = a[0], y = 0 , z = 0;
    FOR(i, 0, N) {
        if(x == a[i]) continue;
        if(x != a[i] ) {
            y =a[i];
            break;
        }
    }
    FOR(i, 0, N) {
        if(x == a[i] || y ==a[i]) continue;
        if(x != a[i] && y != a[i]) {
            z =a[i];
            break;
        }
    }
    FOR(i, 0, N) {
        if((x == a[i] || y ==a[i] || z ==a[i]) && i != N -1) continue;
        if(x != a[i] && y != a[i] && z != a[i]) {
            cout << -1 << endl;
            break;
        }
        if(i == N - 1) {
            if (y == 0) {
                cout << 0 <<endl;
                break;
            }
            else if (z == 0){
                int k = abs(x-y);
                if(k % 2 == 1) {
                cout << k << endl;
                break;
                }
                else {
                    cout << k/2 << endl;
                    break;
                }
            }
            else {
                if(abs(x-y) == abs(y-z)) {
                    cout << abs(x-y) << endl;
                    break;
                }
                else if(abs(y-x) == abs(x-z)) {
                    cout << abs(x-y) << endl;
                    break;
                }
                else if(abs(x-z) == abs(z-y)) {
                    cout << abs(x-z) << endl;
                    break;
                }
                else {
                    cout << -1 << endl;
                    break;
                }
            }
        } 
    }
}