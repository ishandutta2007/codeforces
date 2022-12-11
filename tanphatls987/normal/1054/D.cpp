#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;


int n,k;
int a[N];
map <int,int> ma;
int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++) a[i] ^= a[i - 1];
    for(int i = 0; i <= n; i++) {
        int val = (a[i] & 1) ? (a[i] ^ ((1 << k) -1)) : a[i];
        ma[val]++;
    }
    long long ans = 1LL * n * (n + 1) / 2;
    for(auto i : ma){
        int p1 = i.second / 2, p2 = i.second - p1;
        ans -= 1LL * p1 * (p1 - 1) /2 + 1LL * p2 * (p2 - 1) / 2;
    }
    cout << ans;
}