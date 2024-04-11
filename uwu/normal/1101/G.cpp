#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

int basis[31];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int tot = 0;
    for (int i = 1; i <= N; ++i){
        int a; cin >> a; tot ^= a;
        for (int j = 30; j >= 0; --j){
            if (!(1 & a >> j)) continue;
            if (!basis[j]){
                basis[j] = a;
                break;
            }
            a ^= basis[j];
        }
    }
    int ans = 0;
    for (int i = 0; i <= 30; ++i){
        ans += (basis[i] > 0);
    }
    cout << (tot == 0 ? -1 : ans) << '\n';
}