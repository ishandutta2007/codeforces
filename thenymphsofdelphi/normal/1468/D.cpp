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

const int N = 2e5 + 5;

int n, m, a, b;
int s[N];

void readTest(){
    cin >> n >> m >> a >> b;
    ForE(i, 1, m){
        cin >> s[i];
    }
}

void resetTest(){
    sort(s + 1, s + 1 + m);
    if (a > b){
        a = n + 1 - a;
        b = n + 1 - b;
    }
}

void solveTest(){
    int stand = b - a - 1, move = b - 1;
    int cnt = 0, sec = 1;
    FordE(i, m, 1){
        if (s[i] <= move - sec){
            sec++;
            cnt++;
        }
    }
    cout << min(cnt, stand) << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    readTest();
    resetTest();
    solveTest();
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