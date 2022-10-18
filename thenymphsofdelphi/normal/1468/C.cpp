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

const int N = 5e5 + 5;

int que, cnt;
int a[N];

void readTest(){
    cin >> que;
    if (que == 1){
        cnt++;
        cin >> a[cnt];
    }
}

set <int> stt1; set <pii> stt2;

void resetTest(){
    
}

void solveTest(){
    if (que == 1){
        stt1.insert(cnt);
        stt2.insert({-a[cnt], cnt});
    }
    if (que == 2){
        int idx = *stt1.begin();
        stt1.erase(stt1.find(idx));
        stt2.erase(stt2.find(make_pair(-a[idx], idx)));
        cout << idx << ' ';
    }
    if (que == 3){
        int idx = (*stt2.begin()).se;
        stt1.erase(stt1.find(idx));
        stt2.erase(stt2.find(make_pair(-a[idx], idx)));
        cout << idx << ' ';
    }
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