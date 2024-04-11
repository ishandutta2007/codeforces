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

struct segnode{
    int type, len;
    int mxval, revmxval;
    int left, revleft;
    int right, revright;
    bool lazy;

    segnode(){
        type = -1; len = 0;
        mxval = 0; revmxval = 0;
        left = 0; revleft = 0;
        right = 0; revright = 0;
        lazy = 0;
    }

    segnode(int t){
        len = 1;
        mxval = 1; revmxval = 1;
        left = 1; revleft = 1;
        right = 1; revright = 1;
        lazy = 0;
        if (!t){
            type = 0;
        }
        else{
            type = 3;
        }
    }
};

segnode segtree[4 * N];

segnode merge(const segnode& lhs, const segnode& rhs){
    if (lhs.type == -1){
        return rhs;
    }
    if (rhs.type == -1){
        return lhs;
    }
    segnode ans;
    ans.type = (lhs.type & 2) + (rhs.type & 1);
    if (!(lhs.type & 1) and !(rhs.type & 2)){ // ?> >?
        ans.len = lhs.len + rhs.len - 1;
        ans.mxval = max(max(lhs.mxval, rhs.mxval), lhs.right + rhs.left);
        ans.revmxval = max(max(lhs.revmxval, rhs.revmxval), lhs.revright + rhs.revleft);
        if (lhs.len == 1){ // > >?
            ans.left = lhs.left + rhs.left;
        }
        else{ // <> >?, ><> >?, <><> >?
            ans.left = lhs.left;
        }
        if (lhs.len == 1 or lhs.len == 2){ // > >?, <> >?
            ans.revleft = lhs.revleft + rhs.revleft;
        }
        else{ // ><> >?, <><> >?
            ans.revleft = lhs.revleft;
        }
        if (rhs.len == 1 or rhs.len == 2){ // ?> >, ?> ><
            ans.right = lhs.right + rhs.right;
        }
        else{ // ?> ><>, ?> ><><
            ans.right = rhs.right;
        }
        if (rhs.len == 1){ // ?> >
            ans.revright = lhs.revright + rhs.revright;
        }
        else{ // ?> ><, ?> ><>, ?> ><><
            ans.revright = rhs.revright;
        }
    }
    if (!(lhs.type & 1) and (rhs.type & 2)){ // ?> <?
        ans.len = lhs.len + rhs.len;
        ans.mxval = max(max(lhs.mxval, rhs.mxval), lhs.right + rhs.left);
        ans.revmxval = max(lhs.revmxval, rhs.revmxval);
        if (lhs.len == 1){ // > <?
            ans.left = lhs.left + rhs.left;
        }
        else{ // <> <?, ><> <?, <><> <?
            ans.left = lhs.left;
        }
        if (0){ // 
            ans.revleft = lhs.revleft + rhs.revleft;
        }
        else{ // > <?, <> <?, ><> <?, <><> <?
            ans.revleft = lhs.revleft;
        }
        if (rhs.len == 1){ // ?> <
            ans.right = lhs.right + rhs.right;
        }
        else{ // ?> <>, ?> <><, ?> <><>
            ans.right = rhs.right;
        }
        if (0){
            ans.revright = lhs.revright + rhs.revright;
        }
        else{ // ?> <, ?> <>, ?> <><, ?> <><>
            ans.revright = rhs.revright;
        }
    }
    if ((lhs.type & 1) and !(rhs.type & 2)){ // ?< >?
        ans.len = lhs.len + rhs.len;
        ans.mxval = max(lhs.mxval, rhs.mxval);
        ans.revmxval = max(max(lhs.revmxval, rhs.revmxval), lhs.revright + rhs.revleft);
        if (0){ // 
            ans.left = lhs.left + rhs.left;
        }
        else{ // < >?, >< >?, <>< >?, ><>< >?
            ans.left = lhs.left;
        }
        if (lhs.len == 1){ // < >?
            ans.revleft = lhs.revleft + rhs.revleft;
        }
        else{ // >< >?, <>< >?, ><>< >?
            ans.revleft = lhs.revleft;
        }
        if (0){ // 
            ans.right = lhs.right + rhs.right;
        }
        else{ // ?< >, ?< ><, ?< ><>, ?< ><><
            ans.right = rhs.right;
        }
        if (rhs.len == 1){ // ?< >
            ans.revright = lhs.revright + rhs.revright;
        }
        else{ // ?< ><, ?< ><>, ?< ><><
            ans.revright = rhs.revright;
        }
    }
    if ((lhs.type & 1) and (rhs.type & 2)){ // ?< <?
        ans.len = lhs.len + rhs.len - 1;
        ans.mxval = max(max(lhs.mxval, rhs.mxval), lhs.right + rhs.left);
        ans.revmxval = max(max(lhs.revmxval, rhs.revmxval), lhs.revright + rhs.revleft);
        if (lhs.len == 1 or lhs.len == 2){ // < <?, >< <?
            ans.left = lhs.left + rhs.left;
        }
        else{ // <>< <?, ><>< <?
            ans.left = lhs.left;
        }
        if (lhs.len == 1){ // < <?
            ans.revleft = lhs.revleft + rhs.revleft;
        }
        else{ // >< <?, <>< <?, ><>< <?
            ans.revleft = lhs.revleft;
        }
        if (rhs.len == 1){ // ?< <
            ans.right = lhs.right + rhs.right;
        }
        else{ // ?< <>, ?< <><, ?< <><>
            ans.right = rhs.right;
        }
        if (rhs.len == 1 or rhs.len == 2){ // ?< <, ?< <>
            ans.revright = lhs.revright + rhs.revright;
        }
        else{ // ?< <><, ?< <><>
            ans.revright = rhs.revright;
        }
    }
    return ans;
}

void down(int id, int l, int r){
    if (!segtree[id].lazy){
        return;
    }
    segtree[id * 2].type ^= 3;
    swap(segtree[id * 2].mxval, segtree[id * 2].revmxval);
    swap(segtree[id * 2].left, segtree[id * 2].revleft);
    swap(segtree[id * 2].right, segtree[id * 2].revright);
    segtree[id * 2].lazy ^= 1;
    segtree[id * 2 + 1].type ^= 3;
    swap(segtree[id * 2 + 1].mxval, segtree[id * 2 + 1].revmxval);
    swap(segtree[id * 2 + 1].left, segtree[id * 2 + 1].revleft);
    swap(segtree[id * 2 + 1].right, segtree[id * 2 + 1].revright);
    segtree[id * 2 + 1].lazy ^= 1;
    segtree[id].lazy = 0;
}

void build(int id, int l, int r, const string& s){
    if (l == r){
        segtree[id] = segnode(s[l - 1] == '<' ? 1 : 0);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid, s);
    build(id * 2 + 1, mid + 1, r, s);
    segtree[id] = merge(segtree[id * 2], segtree[id * 2 + 1]);
}

void update(int id, int l, int r, int u, int v){
    if (v < l or r < u){
        return;
    }
    if (u <= l and r <= v){
        segtree[id].type ^= 3;
        swap(segtree[id].mxval, segtree[id].revmxval);
        swap(segtree[id].left, segtree[id].revleft);
        swap(segtree[id].right, segtree[id].revright);
        segtree[id].lazy ^= 1;
        return;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, u, v);
    update(id * 2 + 1, mid + 1, r, u, v);
    segtree[id] = merge(segtree[id * 2], segtree[id * 2 + 1]);
}

segnode get(int id, int l, int r, int u, int v){
    if (v < l or r < u){
        return segnode();
    }
    if (u <= l and r <= v){
        return segtree[id];
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    segnode ans = merge(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
    return ans;
}

int n, q;
string s;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> n >> q;
    cin >> s;
    build(1, 1, n, s);
    while (q--){
        int l, r; cin >> l >> r;
        update(1, 1, n, l, r);
        cout << get(1, 1, n, l, r).mxval << endl;
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