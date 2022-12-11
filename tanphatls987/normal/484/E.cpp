#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

#define X first
#define Y second

const int N = 1e5 + 10;
struct {
    int info[N << 2], laz[N << 2];
    void reset() {
        memset(info, 0, sizeof(info));
        memset(laz, 0, sizeof(laz));
    }
    void lazyupdate(int node, int L, int R) {
        info[node] += laz[node];
        if (L < R) {
            laz[node * 2] += laz[node];
            laz[node * 2 + 1] += laz[node];
        }
        laz[node] = 0;
    }
    void rangeupd(int node, int L, int R, int l, int r, int val) {
        lazyupdate(node, L, R);
        if (L > r || R < l) return;
        if (l <= L && R <= r) {
            laz[node] += val;
            lazyupdate(node, L, R);
            return;
        }
        rangeupd(node * 2, L, (L + R) / 2, l, r, val);
        rangeupd(node * 2 + 1, (L + R) / 2 + 1, R, l, r, val);
        info[node] = max(info[node * 2], info[node * 2 + 1]);
    }
    int get(int node, int L, int R, int l, int r) {
        lazyupdate(node, L, R);
        if (L > r || R < l) return 0;
        if (l <= L && R <= r) return info[node];
        return max(get(node * 2, L, (L + R) / 2, l, r), get(node * 2 + 1, (L + R) / 2 + 1, R, l, r));
    }
}mseg;
struct {
    int tr[N]; 
    int h[N];
    void reset() {
        memset(tr, -1, sizeof(tr));
        memset(h, 0, sizeof(h));
    }
    void merge(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        if (tr[x] < tr[y]) swap(x, y);
        tr[y] += tr[x];
        tr[x] = y;
    }
    int root(int x) {
        if (tr[x] < 0) return x;
        return tr[x] = root(tr[x]);
    }
    int size(int x) {
        if (!h[x]) return 0;
        return -tr[root(x)];
    }
    void mark(int x) {
        h[x] = 1;
        for(int i = -1; i <= 1; i += 2) if (h[x + i]) 
            merge(x, x + i);
    }
}mdsu;
int n, test;
int a[N];
int qu[N][3];
int pa[N];


vector <int> imp[N];
vector <int> impl[N];

int getpos(int height) {
    int L = 1, R = n;
    while (L <= R) {
        int mid = (L + R) / 2;
        if (height > a[pa[mid]]) L = mid + 1;
        else R = mid - 1;
    }
    return L;
}
void iterate(int pass[N], int brange[N][2]) {
    mseg.reset();
    mdsu.reset();

    int heightl = min(n, a[pa[n]]);
    for(int en = n; en >= 1;) {
        int st = en;
        while (en && a[pa[en]] == a[pa[st]]) {
            int pos = pa[en];
            int left = mdsu.size(pos - 1);
            int right = mdsu.size(pos + 1);
            mseg.rangeupd(1, 1, n, pos - left, pos, right + 1);
            mdsu.mark(pos);
            en--;
        }
        for(auto j: imp[en + 1]) {
            if (mseg.get(1, 1, n, qu[j][0], qu[j][1] - qu[j][2] + 1) >= qu[j][2]) {
                pass[j] = 1;
            }
        }
        /*while (heightl > a[pa[en]]) {
            for(auto j : impl[heightl]) {
                if (brange[j][0] <= brange[j][1]) {
                    int mid = (brange[j][0] + brange[j][1]) / 2;
                    if (mid <= qu[j][1] - qu[j][0] + 1) {
                        if (mseg.get(1, 1, n, qu[j][0], qu[j][1] - mid + 1) >= mid)
                            pass[j] = 1;
                    }
                }
            }
            heightl--;
        } */       
    }
}
void solve() {
    int brange[N][2];
    int pass[N];
    for(int i = 1; i <= test; i++) {
        brange[i][0] = 1, brange[i][1] = 1e9 + 10;
    }
    for(int i = 1; i <= test; i++) {
        impl[qu[i][2]].push_back(i);
    }


    while (1) {
        bool rem = 0;
        for(int i = 1; i <= n + 1; i++) imp[i].clear();
        for(int i = 1; i <= test; i++) {
            if (brange[i][0] <= brange[i][1]) {
                rem = true;
                int mid = (brange[i][0] + brange[i][1]) / 2;
                imp[getpos(mid)].push_back(i);
            }
        }
        if (!rem) break;
        memset(pass, 0, sizeof(pass));
        iterate(pass, brange);
        for(int i = 1; i <= test; i++) {
            if (brange[i][0] <= brange[i][1]) {
                int mid = (brange[i][0] + brange[i][1]) / 2;
                if (pass[i]) brange[i][0] = mid + 1;
                else brange[i][1] = mid - 1;
            }
        }
    }
    for(int i = 1; i <= test; i++) cout << brange[i][1] << '\n';
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) pa[i] = i;
    sort(pa + 1, pa + n + 1, [](int x, int y){
        return a[x] < a[y];
    });
    cin >> test;
    for(int i = 1; i <= test; i++) {
        for(int j = 0; j < 3; j++) cin >> qu[i][j];
    }
    solve();
}