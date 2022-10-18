#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

// #define endl '\n'
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

const int N = 4e5 + 5;

int n;
pii a[N];
int face[N], opp[N];

int cal(int x){ // x -> 2n + 1 - x
    // cout << "CAL " << x << endl;
    if (x >= n + 1){
        return 0;
    }
    if (opp[2 * n + 1 - x] == x){
        return cal(x + 1);
    }
    if (opp[x] < opp[2 * n + 1 - x]){
        cout << -1 << endl;
        exit(0);
    }
    int tans = face[x] + face[2 * n + 1 - x], len = 2;
    int l2 = opp[x], r2 = opp[2 * n + 1 - x];
    unordered_set <int> stt; stt.insert(x); stt.insert(2 * n + 1 - x);
    stt.insert(opp[x]); stt.insert(opp[2 * n + 1 - x]);
    int mexmnx = x, mexmxx = 2 * n + 1 - x;
    while (stt.find(mexmnx) != stt.end()) mexmnx++;
    while (stt.find(mexmxx) != stt.end()) mexmxx--;
    while (1){
        // cout << mexmnx << ' ' << mexmxx << endl;
        if (mexmnx > 2 * n + 1 - x or mexmxx < x){
            break;
        }
        if (mexmnx != r2 + 1){
            if (opp[mexmnx] > l2 or opp[mexmnx] < r2){
                cout << -1 << endl;
                exit(0);
            }
            tans += face[mexmnx];
            len++;
            l2 = opp[mexmnx];
            stt.insert(mexmnx); stt.insert(opp[mexmnx]);
            while (stt.find(mexmnx) != stt.end()) mexmnx++;
            while (stt.find(mexmxx) != stt.end()) mexmxx--;
            continue;
        }
        if (mexmxx != l2 - 1){
            if (opp[mexmxx] > l2 or opp[mexmnx] < r2){
                cout << -1 << endl;
                exit(0);
            }
            tans += face[mexmxx];
            len++;
            r2 = opp[mexmxx];
            stt.insert(mexmxx); stt.insert(opp[mexmxx]);
            while (stt.find(mexmnx) != stt.end()) mexmnx++;
            while (stt.find(mexmxx) != stt.end()) mexmxx--;
            continue;
        }
        break;
    }
    return min(tans, len - tans) + cal(x + len);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i].fi >> a[i].se;
        face[a[i].fi] = 0; face[a[i].se] = 1;
        opp[a[i].fi] = a[i].se; opp[a[i].se] = a[i].fi;
    }
    cout << cal(1) << endl;
}

/*
==================================+
INPUT:                            |
------------------------------    |
5
3 10
6 4
1 9
5 7
2 8
------------------------------    |
5
3 10
5 4
1 9
6 8
2 7
------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |
1
------------------------------    |
-1
------------------------------    |
==================================+
*/