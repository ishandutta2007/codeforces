#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4")

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 3e5 + 5, M = 1e1 + 5;

int n, m, k;
int a[N];

void readTest(){
    cin >> n >> m >> k;
    ForE(i, 1, n){
        cin >> a[i];
    }
}

ll ansGroup[M];

void solveTest(){
    ll ans = 0;
    ForE(i, 1, n){
        For(j, 0, m){
            if ((j == 0 ? m : j) < i){
                ansGroup[j] += a[i];
            }
            if (i % m == j){
                ansGroup[j] = max(ansGroup[j], (ll)a[i]);
                ansGroup[j] -= k;
            }
        }
        For(j, 0, m){
            ans = max(ans, ansGroup[j]);
        }
    }
    cout << ans << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    readTest();
    solveTest();
}