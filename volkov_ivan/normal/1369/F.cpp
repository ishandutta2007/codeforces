#include <bits/stdc++.h>
#define int long long

using namespace std;

int win1(int s, int e) {
    int x = e;
    while (1) {
        int l = (x % 2 == 1 ? 0 : x / 2);
        if (s > l) {
            if (s % 2 == x % 2) return 0;
            return 1;
        }
        int lst = l + 1;
        if (lst % 2 != x % 2) lst++;
        l = lst / 2;
        if (s >= l) return 1;
        x = l - 1;
    }
}

int win2(int s, int e) {
    int l = (e + 2) / 2;
    if (s >= l) return 1;
    return win1(s, l - 1);
}

signed main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("Desktop/input.txt", "r", stdin);
    int t;
    cin >> t;
    bool poss1 = 1, poss2 = 0;
    for (int i = 0; i < t; i++) {
        int s, e;
        cin >> s >> e; 
        int w1 = win1(s, e), w2 = win2(s, e);
        bool nposs1 = 0, nposs2 = 0;
        if (poss1) {
            if (w1) nposs2 = 1;
            if (w2) nposs1 = 1;
        }
        if (poss2) {
            if (!w1) nposs2 = 1;
            if (!w2) nposs1 = 1;
        }
        poss1 = nposs1;
        poss2 = nposs2;
    }
    cout << poss2 << ' ' << poss1 << endl;
    return 0;
}