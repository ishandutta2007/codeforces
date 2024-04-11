#include <bits/stdc++.h>

#define lsort(a) sort(a.begin(), a.end())
#define gsort(a) sort(a.rbegin(), a.rend())

//#define TEST

#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll a, b, c;
    cin >> a >> b >> c;

    ll ans = c * 2;
    ans += min(a, b) * 2;
    if(a > min(a, b) || b > min(a, b)){
        ans++;
    }
    cout << ans << "\n";
    
    return 0;
}