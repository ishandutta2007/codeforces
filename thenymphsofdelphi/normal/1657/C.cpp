#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

const int N = 5e5 + 5;

// p[0][i]: half length of even pal substring around i, p[1][i]: half length(rounded down) of odd pal substring
// O(n)
template<class Char_Type>
array<vector<int>, 2> manacher(const vector<Char_Type> &s){
    int n = (int)s.size();
    array<vector<int>, 2> p = {vector<int>(n + 1), vector<int>(n)};
    for(auto z = 0; z < 2; ++ z){
        for(auto i = 0, l = 0, r = 0; i < n; ++ i){
            int t = r - i + !z;
            if(i < r) p[z][i] = min(t, p[z][l + t]);
            int L = i - p[z][i], R = i + p[z][i] - !z;
            while(L >= 1 && R + 1 < n && s[L - 1] == s[R + 1]) ++ p[z][i], -- L, ++ R;
            if(R > r) l = L, r = R;
        }
    }
    return p;
}

bool query_palin(int l, int r, const array<vector<int>, 2>& cacpalin){
    if ((r - l + 1) & 1){
        return cacpalin[1][(l + r) >> 1] >= (r - l + 1) / 2;
    }
    else{
        return cacpalin[0][(l + r + 1) >> 1] >= (r - l + 1) / 2;
    }
}

// Specialization of sparse_table
// Range min query by default. Set cmp = greater for max query
template<class T, class Compare = less<>>
struct range_minmax_query_solver{
    int n;
    vector<vector<T>> data;
    Compare cmp;
    T T_id;
    range_minmax_query_solver(){ }
    // O(n log n)
    range_minmax_query_solver(const vector<T> &a, Compare cmp = less<>(), T T_id = numeric_limits<T>::max()): n((int)a.size()), cmp(cmp), T_id(T_id), data({a}){ // O(n log n)
        for(auto p = 1, i = 1; p << 1 <= n; p <<= 1, ++ i){
            data.emplace_back(n - (p << 1) + 1);
            for(auto j = 0; j < (int)data[i].size(); ++ j) data[i][j] = cmp(data[i - 1][j], data[i - 1][j + p]) ? data[i - 1][j] : data[i - 1][j + p];
        }
    }
    // O(1)
    T query(int l, int r) const{
        assert(0 <= l && l <= r && r <= n);
        if(l == r) return T_id;
        int d = __lg(r - l);
        return cmp(data[d][l], data[d][r - (1 << d)]) ? data[d][l] : data[d][r - (1 << d)];
    }
};

int n;
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
int tests; cin >> tests; while (tests--){
    cin >> n >> s;

    vi a(n + 1, 0);
    ForE(i, 1, n){
        a[i] = a[i - 1] + (s[i - 1] == '(' ? 1 : -1);
    }
    vector <char> ss(bend(s));
    auto cacpalin = manacher(ss);
    auto cacrmq = range_minmax_query_solver(a);

    int ans1 = 0, ans2 = n;
    int l = 0;
    while (l < n){
        int r = l;
        while (r < n and !(a[l] == a[r + 1] and cacrmq.query(l + 1, r + 2) == a[l]) and !(query_palin(l, r, cacpalin) and r - l + 1 >= 2)){
            r++;
        }
        if (r == n){
            break;
        }
        ans1++; ans2 -= r - l + 1;
        l = r + 1;
    }
    cout << ans1 << ' ' << ans2 << endl;
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