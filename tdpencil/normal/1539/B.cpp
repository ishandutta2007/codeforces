#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAXN = 1e5;
int A[MAXN], B[MAXN];
struct Node {
    ll val, lazy;
};
Node nodes[MAXN << 2];

ll combine(Node &x, Node &y)  {
    return x.val + y.val;
}
void build(int v, int t1, int t2) {
    if(t1 == t2) {
        nodes[v].val = A[t1];
        nodes[v].lazy = 0;
    } else {
        int mid = (t1 + t2) >> 1;
        build(v << 1, t1, mid);
        build(v << 1 | 1, mid + 1, t2);
        nodes[v].val = combine(nodes[v << 1], nodes[v << 1 | 1]);
    }
}

void prop(int v) {
    nodes[v << 1].lazy = nodes[v].lazy;
    nodes[v << 1].val = nodes[v].lazy;
    nodes[v << 1 | 1].lazy = nodes[v].lazy;
    nodes[v << 1 | 1].val = nodes[v].lazy;
    nodes[v].lazy = 0;
}

void modupdate(int v, int t1, int t2, int l, int r, int val) {
    prop(v);
    if(l > t2 || r < t1)
        return;
    else if(l <= t1 && r >= t2) {
        nodes[v].lazy = (t2-t1+1)*nodes[v].lazy % val;
        nodes[v].val = (t2 - t1 + 1) * nodes[v].lazy % val;
    } else {
        int mid = (t1 + t2) >> 1;
        modupdate(v << 1, t1, mid, l, r, val);
        modupdate(v << 1 | 1, mid + 1, t2, l, r, val);
        nodes[v].val = combine(nodes[v << 1], nodes[v << 1|1]);
    }
}
#define lb lower_bound
#define ub upper_bound
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k;
    cin >> n >> k;
    string s; cin >> s;
    vector<vector<int>> pos(26);

    for(int i = 0; i < n; i++) {
        pos[s[i] - 'a'].push_back(i);
    }

    while(k--) {
        int l, r;
        cin >> l >> r;
        --l, --r;

        int ans = 0;
        for(int i = 0; i < 26; i++)
            ans += ((ub(pos[i].begin(), pos[i].end(), r) - pos[i].begin()) - (lb(pos[i].begin(), pos[i].end(), l) - pos[i].begin())) * (i + 1);;

        cout << ans << "\n";
    }
    
}