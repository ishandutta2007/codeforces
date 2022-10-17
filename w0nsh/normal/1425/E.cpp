#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define sz(s) (int)s.size()
#define pb push_back
#define all(s) s.begin(), s.end()
#define f first
#define s second
#define FOR(i, s) for(int i = 0; i < s; i++)

typedef long long ll;

const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const ll BIG_INF = 1e18;
const int T = (1<<19);

#define ii pair<int, int>
#define vi vector<int>
#define vii vector<pair<int, int> >
#define vvi vector<vector<int> >

template<class T> inline T gcd(T a, T b) { while (b)swap(a %= b, b); return abs(a); }

void solve(){
    int n, k;
    cin >> n >> k;

    vi A(n), B(n);
    for(auto & u : A)
        cin >> u;

    for(auto & u : B)
        cin >> u;

    if(k == 0){
        ll suma = 0;
        ll ret = 0;

        for(int i = n - 1; i >= 0; i--){
            suma += A[i];
            ret = max(ret, suma - B[i]);
        }
        cout << ret << '\n';
    }
    else if(k == 1){
        // case z cyklem
        ll suma_pref = 0;
        ll suma_suf = 0;

        for(int i = 2; i < n; i++)
            suma_suf += A[i];

        suma_pref = A[0] + A[1];
        int mini = min(B[0], B[1]);
        ll ret = 0;
        
        for(int i = 2; i < n; i++){
            ret = max(ret, max(0ll, suma_pref - mini) + max(0ll, suma_suf - B[i]));
            // cout << i << ' ' << suma_pref << ' ' << suma_suf << ' ' << max(0ll, suma_pref - mini) + max(0ll, suma_suf - B[i]) << endl;
            if(i < n - 1){
                mini = min(mini, B[i]);
                suma_pref += A[i];
                suma_suf -= A[i];
            }
        }

        // klikam dowolnego innego niz 1 bez cofania
        ll suma = 0;
        for(int i = n - 1; i >= 1; i--){
            suma += A[i];
            ret = max(ret, suma - B[i]);
        }

        // klikam pierwszego wiec musze pominac dowolnego jednego (i potem poze go kliknac)

        suma = -B[0];
        for(int i = 0; i < n; i++)
            suma += A[i];
        for(int i = 1; i < n; i++)
            ret = max(ret, suma - A[i] + max(0, A[i] - B[i]));
        cout << ret << '\n';
    }
    else{
        ll suma = 0;
        int mini = INF;

        for(int i = 0; i < n - 1; i++){
            suma += A[i];
            mini = min(mini, B[i]);
        }
        cout << max({0ll, suma - mini + A[n - 1], (ll) A[n - 1] - B[n - 1]}) << '\n';
    }
}   

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
}