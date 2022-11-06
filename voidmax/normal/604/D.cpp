/*
 - - - - - - - -
 
 ********
 **********
 ***    ****
 ***     ***
 ***     ***
 ***     ***
 ***     ***
 ***    ****
 **********
 ********
 
 - - - - - - - -
 */

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define x first
#define y second

using namespace std;

typedef unsigned long long ll;

int n, k;
ll arr[1000001];
bool used[1000001][2];
ll deep[1000001];

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> k;
    if (k == 0) {
        ll ans = 1;
        For(i, 1, n) {
            ans *= n;
            ans %= (int)1e9 + 7;
        }
        cout << ans << endl;
        return 0;
    }
    For(i, 0, n) arr[i] = (ll)i * k % n;
    For(i, 0, n) {
        if (!used[i][0]) {
            int D = 0;
            ll s = i;
            while (!used[s][0]) {
                used[s][0] = true;
                ++D; s = arr[s];
            }
            ++deep[D];
        }
    }
    ll ans = 1;
    For(i, 0, n) {
        if (!used[i][1]) {
            int D = 0;
            ll s = i;
            while (!used[s][1]) {
                used[s][1] = true;
                ++D; s = arr[s];
            }
            ll sum = 0;
            For(j, 1, D + 1) {
                if (j * j >= D) break;
                if (D % j == 0) {
                    sum = (sum + ((deep[j] * j) % ((int)1e9 + 7))) % ((int)1e9 + 7);
                    sum = (sum + ((deep[D / j] * D / j) % ((int)1e9 + 7))) % ((int)1e9 + 7);
                }
            }
            if (sqrt(D) * sqrt(D) == D) sum = (sum + ((deep[(int)sqrt(D)] * (int)sqrt(D)) % ((int)1e9 + 7))) % ((int)1e9 + 7);

            sum %= (int)1e9 + 7;
            ans *= sum;
            ans %= (int)1e9 + 7;
        }
    }
    cout << ans << endl;
}
//0 4 3 2 1