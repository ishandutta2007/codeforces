#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#pragma GCC optimize("O3")
//#pragma GCC optimize ("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")

using namespace std;
using namespace __gnu_pbds;

typedef long double ld;
typedef long long ll;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

#define _ inline
#define f first
#define sec second
#define pb push_back
#define ins insert
#define ers erase
#define mk make_pair
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define int ll
#define forn(i, n) for (register int i(1); i <= n; i++)
#define fore(i, n) for (register int i(0); i < n; i++)

#define right rightt
#define left leftt
#define prev prevv
#define next nextt

mt19937 Random(time(0));

const int INF = 1e9 + 10;
const int MOD = 1e9 + 7;
const int P = 239017;
const long long BINF = 1e18 + 10;

_ void source() {
    int n;
    string s1, s2, s3;
    map<char, int> mp1, mp2, mp3;
    cin >> n;
    cin >> s1 >> s2 >> s3;
    int sz = s1.size();
    for (auto it : s1) {
        mp1[it]++;
    }
    for (auto it : s2) {
        mp2[it]++;
    }
    for (auto it : s3) {
        mp3[it]++;
    }
    int mx1 = 0, mx2 = 0, mx3 = 0;
    for (auto it : mp1) {
        mx1 = max(mx1, it.sec);
    }
    for (auto it : mp2) {
        mx2 = max(mx2, it.sec);
    }
    for (auto it : mp3) {
        mx3 = max(mx3, it.sec);
    }
    if (mx1 != sz || n != 1) mx1 = min(sz, mx1 + n);
    else mx1--;
    if (mx2 != sz || n != 1) mx2 = min(sz, mx2 + n);
    else mx2--;
    if (mx3 != sz || n != 1) mx3 = min(sz, mx3 + n);
    else mx3--;
    if (mx1 > mx2 && mx1 > mx3) {
        cout << "Kuro";
    }
    else if (mx2 > mx1 && mx2 > mx3) {
        cout << "Shiro";
    }
    else if (mx3 > mx1 && mx3 > mx2) {
        cout << "Katie";
    }
    else {
        cout << "Draw";
    }
}

signed main() {
#ifdef EXTRATERRESTRIAL_
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    source();
    return 0;
}