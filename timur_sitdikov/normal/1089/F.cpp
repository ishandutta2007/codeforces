#include <bits/stdc++.h>
using namespace std;


#define file "file"
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef complex<double> point;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define DEBUG 0
#define dout if(DEBUG) cout

int gcd(int a, int b){
    if(!b) return a;
    return gcd(b, a % b);
}

void solve(){
    int n;
    cin >> n;
    int a = -1, b = -1;
    for(int i = 2; i * i <= n; i++){
        if(n % i == 0 && gcd(i, n / i) == 1){
           a = i;
           b = n / i;
           break;
        }
    }
    if(a > b) swap(a, b);
    if(a == -1){
        cout << "NO";
        return;
    }
    int lim = n / b;
    for(ll y = 1; y < n / b; y++){
        ll cur = 1ll * a * b - 1 - y * b;
        if(cur > 0 && cur % a == 0){
            ll x = cur / a;
            cout << "YES\n";
            cout << 2 << endl;
            cout << y << " " << a << endl;
            cout << x << " " << b << endl;
            return;
        }
    }
    cout << "NO";
}

int main() {
    #ifdef NASTYA
        assert(freopen("input.txt", "r", stdin)); assert(freopen("output.txt", "w", stdout));
    #else
    // assert(freopen(file".in", "r", stdin)); assert(freopen(file".out", "w", stdout));
    #endif
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}