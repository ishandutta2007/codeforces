#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

struct SegTree {
    vector<pair<bool, bool>> V; // flip positive, flip negative
    int len;

    SegTree(int n) {
        for (len = 1; len < n; len *= 2);
        V.resize(len*2);
    }

    void apply(int i, pair<bool, bool> op) {
        V[i].x = (V[i].x ? !op.y : op.x);
        V[i].y = (V[i].y ? !op.x : op.y);
    }

    void push(int i) {
        apply(i*2, V[i]);
        apply(i*2+1, V[i]);
        V[i] = {0, 0};
    }

    void modify(int vBegin, int vEnd, pair<bool, bool> op, int i = 1, int begin = 0, int end = -1) {
        if (end < 0) end = len;
        if (vBegin >= end || begin >= vEnd) return;

        if (vBegin <= begin && vEnd >= end) {
            apply(i, op);
            return;
        }

        int mid = (begin+end) / 2;
        push(i);
        modify(vBegin, vEnd, op, i*2, begin, mid);
        modify(vBegin, vEnd, op, i*2+1, mid, end);
    }

    void modify(char op, int val) {
        if (op == '<') {
            if (val <= 1) {
                modify(-val+1, len, {0, 1});
            } else {
                modify(val, len, {0, 1});
                modify(0, val, {1, 1});
            }
        } else {
            if (val >= -1) {
                modify(val+1, len, {1, 0});
            } else {
                modify(-val, len, {1, 0});
                modify(0, -val, {1, 1});
            }
        }
    }

    void forcePush() {
        rep(i, 1, len) push(i);
    }

    int get(int i) {
        if (i >= 0) {
            return V[len+i].x ? -i : i;
        }
        return V[len-i].y ? -i : i;
    }
};

void run() {
    int n, q; cin >> n >> q;
    Vi elems(n);
    each(e, elems) cin >> e;

    SegTree tree(1e5+1);

    while (q--) {
        string s;
        int x;
        cin >> s >> x;
        tree.modify(s[0], x);
    }

    tree.forcePush();
    each(e, elems) cout << tree.get(e) << ' ';
}