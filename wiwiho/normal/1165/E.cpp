#include <bits/stdc++.h>

#define lsort(a) sort(a.begin(), a.end())
#define gsort(a) sort(a.rbegin(), a.rend())

//#define TEST

#define MOD 998244353

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<ll> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        a[i] = a[i] * (i + 1) * (n - i);
    }
    lsort(a);

    vector<ll> b(n);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }
    gsort(b);

    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans = (ans + (((a[i] % MOD) * b[i]) % MOD)) % MOD;
    }
    cout << ans << "\n";
    
    return 0;
}