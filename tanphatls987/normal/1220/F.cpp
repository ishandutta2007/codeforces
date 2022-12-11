#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int MOD = 1e9 + 7;
const int N = 4e5 + 10;

int n;
int trR[N], trL[N];
int a[N];
vector<int> adj[N];
int pa[N];
struct {
#define mid ((L + R) / 2)
    int laz[N << 2];
    int A[N << 2];

    void lazyUpdate(int node, int L, int R) {
        A[node] += laz[node];
        if (L < R) {
            for(int i = 0; i <= 1; i++) 
                laz[node * 2 + i] += laz[node];
        }
        laz[node] = 0;
    }
    void add(int node, int L, int R, int l, int r, int val) {
        lazyUpdate(node, L, R);
        if (L > r || R < l) return;
        if (l <= L && R <= r) {
            laz[node] += val;
            lazyUpdate(node, L, R);
            return;
        }
        add(node * 2, L, mid, l, r, val);
        add(node * 2 + 1, mid + 1, R, l, r, val);
        A[node] = max(A[node * 2], A[node * 2 + 1]);
    }
    void add(int l, int r, int val) {
        if (l > r) return;
        add(1, 1, 2 * n, l, r, val);
    }
    int get(int node, int L, int R, int l, int r) {
        lazyUpdate(node, L, R);
        if (L > r || R < l) return 0;
        if (l <= L && R <= r) return A[node];
        return max(get(node * 2, L, mid, l, r), get(node * 2 + 1, mid + 1, R, l, r));
    }
    int get(int l, int r) {
        return get(1, 1, 2 * n, l, r);
    }
#undef mid
}mSeg;

void DFS(int L, int R, int pos) {
    //cout << L << " " << R << " " << pos << endl;
    mSeg.add(L, R, 1);
    for(auto u : adj[pos]) {
        if (u < pos) 
            DFS(L, pos - 1, u);
        else DFS(pos + 1, R, u);
    }
}
void init() {
    for(int i = 1; i <= n; i++) a[n + i] = a[i];

    a[2 * n + 1] = -1;
    vector<int> stR = {2 * n + 1};
    for(int i = 2 * n; i >= 1; i--) {
        while (a[stR.back()] > a[i]) stR.pop_back();
        trR[i] = stR.back();
        stR.push_back(i);
    }
    a[0] = -1;
    vector<int> stL = {0};
    for(int i = 1; i <= 2 * n; i++) {
        while (a[stL.back()] > a[i]) stL.pop_back();
        trL[i] = stL.back();
        stL.push_back(i);
    }

    for(int i = 1; i < n; i++) {
        pa[i] = trL[i];
        if (a[trR[i]] > a[pa[i]]) pa[i] = trR[i];
        adj[pa[i]].push_back(i);
    }
    DFS(1, n, n);
}
void solve() {
    int shift = find(a + 1, a + n + 1, 1) - a;
    for(int i = 1; i <= shift; i++) a[n + i] = a[i];
    for(int i = 1; i <= n; i++) a[i] = a[shift + i];
    
    init();

    vector<int> ans(n, 0);
    ans[0] = mSeg.get(1, n);
    /*
    for(int i = 1; i <= n; i++) cout << a[i] << " "; cout << endl;
    for(int i = 1; i <= n; i++) cout << pa[i] << " "; cout << endl;
    for(int i = 1; i <= n; i++) cout << mSeg.get(i, i) << " ";
    cout << endl;
    */
    for(int i = 1; i < n; i++) {
        mSeg.add(i, trR[i] - 1, -1);
        mSeg.add(trL[n + i] + 1, n + i - 1, 1);
        mSeg.add(n + i, n + i, mSeg.get(trL[n + i], trL[n + i]) + 1);
        ans[i] = mSeg.get(i + 1, n + i);
        //for(int j = 1; j <= n; j++) cout << mSeg.get(i + j, i + j) << " ";
        //cout << endl;
    }

    int ansp = min_element(ans.begin(), ans.end()) - ans.begin();

    cout << ans[ansp] << " " << (shift + ansp) % n;
}
void prepare() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    prepare();
    solve();

}