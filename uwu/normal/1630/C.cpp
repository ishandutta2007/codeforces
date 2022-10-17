#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;
int a[MN], l[MN], r[MN], ord[MN];
struct Fenwick{
    int a[2 * MN];
    void upd(int i){ for (; i < 2 * MN; i += i & -i) a[i]++; }
    int qry(int i){
        int ret = 0;
        for (; i; i -= i & -i) ret += a[i];
        return ret;
    }
} bit;
struct Eve{
    int x, id, c;
    bool operator<(const Eve &other){
        return x < other.x;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        cin >> a[i];
        if (!l[a[i]]) l[a[i]] = i;
        r[a[i]] = i;
    }
    vector<int> ord;
    for (int i = 1; i <= N; ++i){
        if (l[i] == r[i]) continue;
        ord.push_back(i);
    }
    sort(ord.begin(), ord.end(), [](int a, int b){ return tie(l[a], r[b]) < tie(l[b], r[a]); });
    vector<Eve> eves;
    int i = 0;
    for (int v : ord){
        i++;
        if (i - bit.qry(r[v] - 1) - 1 == 0){
            eves.push_back({l[v], v, 1});
            eves.push_back({r[v], v, 0});
        }
        bit.upd(r[v]);
    }
    sort(eves.begin(), eves.end());
    int lst = 0, tar = 0, nxt = 0, cnt = 0, ans = N;
    for (auto [x, id, c] : eves){
        if (c == 1){
            if (cnt == 0){
                ans -= (x - lst - 1);
                nxt = r[id];
                ans--;
            }
            cnt++;
            tar = r[id];
        }
        if (c == 0){
            cnt--;
            if (cnt == 0){
                ans--;
                lst = x;
            }
            else if (x == nxt){
                nxt = tar;
                ans--;
            }
        }
    }
    ans -= N - lst;
    cout << ans << '\n';
}