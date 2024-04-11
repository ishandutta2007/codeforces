#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <cmath>
#define LL long long
#define pii pair <int, int>
#define piii pair <int, pii>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define pis pair <int, string>
using namespace std;

const int N = 200100;
pis a[N];
string s;
set <string> st;

int main () {
//    freopen ("in.txt", "r", stdin);
    ios::sync_with_stdio (0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        a[i] = pis (i, s);
    }
    sort (a + 1, a + 1 + n);
    for (int i = n; i >= 1; i--) {
        if (st.find (a[i].yy) != st.end()) continue;
        cout << a[i].yy << endl;
        st.insert (a[i].yy);
    }
}