#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int n, a[N], per[N];
long long m, tot;
struct {
    long long b[N << 2];
    int pop[N << 2];
    void build(int node, int L, int R){
        b[node] = pop[node] = 0;
        if (L == R) return;
        build(node * 2, L, (L + R) / 2);
        build(node * 2 + 1, (L + R) / 2 + 1, R);
    }
    void update(int node, int L, int R, int pos, int val){
        if (L > pos || R < pos) return;
        if (L == R){
            b[node] += val;
            pop[node]++;
            return;
        }
        update(node * 2, L , (L + R) / 2, pos, val);
        update(node * 2 + 1, (L + R) / 2 + 1, R, pos, val);
        b[node] = b[node * 2] + b[node * 2 + 1];
        pop[node] = pop[node * 2] + pop[node * 2 + 1];
    }
    long long getpref(int node, int L, int R, int per){
        if (per == 0) return 0;
        if (L == R)
            return b[node];
        int mid = (L + R) / 2;
        int leftpop = pop[node * 2];
        if (leftpop >= per)     
            return getpref(node * 2, L, mid, per);
        else return b[node * 2] + getpref(node * 2 + 1, mid + 1, R, per - leftpop);
    }
}mseg;
void prepare() {
    cin >> n >> m >> tot;
    for(int i = 1; i <= n; i++) cin >> a[i];
    mseg.build(1, 1, n);
    for(int i = 1; i <= n; i++) per[i] = i;
    sort(per + 1, per + n + 1,[](int x, int y) {return a[x] < a[y];});
}

void solve(){
    int ans = 0 , use = 1;
    for(int en = 1; en <= n;){
        int st = en;
        while (en <= n && a[per[en]] == a[per[st]]){
            mseg.update(1, 1, n, per[en], a[per[en]]);
            en++;
        }
        int L = 1, R = en - 1;
        while (L <= R){
            int mid = (L + R) / 2;
            int mulm = (mid - 1) / m * m;
            long long req = mseg.getpref(1, 1, n, mid) + mseg.getpref(1, 1, n, mulm);
            if (req <= tot) L = mid + 1;
            else R = mid - 1;
        }
        if (ans < R) ans = R, use = a[per[st]];
    }
    cout << ans << " " << use <<'\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--){
        prepare();
        //cout << "ick\n";
        solve();
    }
}