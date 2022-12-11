#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;
const int M = 2e5 + 10;
int n, k, m;
vector<int> pv;
struct {
    long long b[M << 2];
    long long pop[M << 2];
    void build(int node, int L, int R){
        b[node] = pop[node] = 0;
        if (L == R) return;
        build(node * 2, L, (L + R) / 2);
        build(node * 2 + 1, (L + R) / 2 + 1, R);
    }
    void update(int node, int L, int R, int pos, long long per){
        if (L > pos || R < pos) return;
        if (L == R){
            b[node] += 1LL * pv[L] * per;
            pop[node]+= per;
            return;
        }
        update(node * 2, L , (L + R) / 2, pos, per);
        update(node * 2 + 1, (L + R) / 2 + 1, R, pos, per);
        b[node] = b[node * 2] + b[node * 2 + 1];
        pop[node] = pop[node * 2] + pop[node * 2 + 1];
    }
    long long getpref(int node, int L, int R, long long per){
        if (L == R) {
            long long use = min(per, pop[node]);
            return use * pv[L];
        }
        int mid = (L + R) / 2;
        long long leftpop = pop[node * 2];
        if (leftpop >= per)     
            return getpref(node * 2, L, mid, per);
        else return b[node * 2] + getpref(node * 2 + 1, mid + 1, R, per - leftpop);
    }
}mseg;

vector<pair<int,int>> imp[N];
void prepare() {
    cin >> n >> k >> m;
    for(int i = 1; i <= m; i++){
        int L, R, ci, pi;
        cin >> L >> R >> ci >> pi;
        imp[L].push_back(make_pair(pi, ci));
        imp[R + 1].push_back(make_pair(pi, -ci));
        pv.push_back(pi);
    }
    sort(pv.begin(), pv.end());
    mseg.build(1, 0, m - 1);
}

long long solve() {
    long long ans = 0;
    for(int i = 1; i <= n; i++){
        for(auto j : imp[i]){
            int pos = lower_bound(pv.begin(), pv.end(), j.first) - pv.begin();
            mseg.update(1, 0, m - 1, pos, j.second);
        }
        ans += mseg.getpref(1, 0, m - 1, k);
    }
    return ans;
}
int main() {
    prepare();
    cout << solve();
}