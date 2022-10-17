#include "bits/stdc++.h"

using namespace std;
typedef long long ll;

struct carttree {
    vector<int> stk, val, ls, rs;
    int tp = 0, tot = 0, rt = -1;
    carttree(vector<int> a) {
        int n = a.size();
        stk.resize(n + 1);
        val.resize(n + 1);
        ls.resize(n + 1);
        rs.resize(n + 1);
        for(int x : a) {
            int k = tp;
            val[++tot] = x;
            while(k && val[stk[k]] < val[tot]) --k; // 
            if(k > 0) rs[stk[k]] = tot;
            if(k < tp) ls[tot] = stk[k + 1];
            stk[++k] = tot;
            tp = k;
        }
        rt = stk[1];
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; ++i) cin >> a[i];
        carttree tr(a);
        vector<ll> sum(n + 1), lmx(n + 1), rmx(n + 1);
        int ok = 1;
        function<void(int)> dfs = [&](int p) {
            sum[p] = tr.val[p];
            if(tr.ls[p]) dfs(tr.ls[p]), sum[p] += sum[tr.ls[p]];
            if(tr.rs[p]) dfs(tr.rs[p]), sum[p] += sum[tr.rs[p]];
            lmx[p] = max(lmx[tr.ls[p]], sum[tr.ls[p]] + tr.val[p] + lmx[tr.rs[p]]);
            rmx[p] = max(rmx[tr.rs[p]], sum[tr.rs[p]] + tr.val[p] + rmx[tr.ls[p]]);
            if(tr.val[p] < tr.val[p] + rmx[tr.ls[p]] + lmx[tr.rs[p]]) ok = 0;
        };
        dfs(tr.rt);
        cout << (ok ? "YES" : "NO") << '\n';
    }
}