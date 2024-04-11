#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

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

const int N = 1e5 + 5;

#define prev __prev__
#define next __next__

int n;
int a[N];
int l[N], r[N];

int prev(int x, int y = 1){
    return ((x - y) % n + n) % n;
}

int next(int x, int y = 1){
    return ((x + y) % n + n) % n;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    cin >> n;
    For(i, 0, n){
        cin >> a[i];
        l[i] = prev(i);
        r[i] = next(i);
    }
    queue <int> qu;
    For(i, 0, n){
        if (__gcd(a[i], a[r[i]]) == 1){
            qu.push(r[i]);
        }
    }
    vi vans;
    while (!qu.empty()){
        int pos = qu.front(); qu.pop();
        vans.push_back(pos);
        int posl = l[pos], posr = r[pos];
        if (posl == pos){
            break;
        }
        if (!qu.empty() && qu.front() == posr){
            qu.pop();
        }
        if (__gcd(a[posl], a[posr]) == 1){
            qu.push(posr);
        }
        r[posl] = posr; l[posr] = posl;
    }
    cout << isz(vans) << ' ';
    Fora(&v, vans){
        cout << v + 1 << ' ';
    } cout << endl;
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/