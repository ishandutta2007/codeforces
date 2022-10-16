#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <numeric>

using namespace std;
using pi = pair<int, int>;

const int N = 5e5+7;
const int V = 1e6+7;

int n, h[N], near[N], rnk[N], srnk[N], fst[N], vs = 1;
string s;
map<pi, int> lab;

int vc, link[V], len[V];
map<int, int> nxt[V];
long long cnt[V], ans;
 
void sa_init() {
    len[0] = 0;
    link[0] = -1;
    cnt[0] = 1;
    vc = 1;
}
 
int sa_push(int last, int ch) {
    int cur = vc++;
    int p = last;
 
    len[cur] = len[last] + 1;
    while (p != -1 && nxt[p].count(ch) == 0) {
        nxt[p][ch] = cur;
        cnt[cur] += cnt[p];
        p = link[p];
    }
 
    if (p == -1) {
        link[cur] = 0;
    } else {
        int q = nxt[p][ch];
        if (len[p] + 1 == len[q]) {
            link[cur] = q;
        } else {
            int clone = vc++;
            len[clone] = len[p] + 1;
            nxt[clone] = nxt[q];
            link[clone] = link[q];
            while (p != -1 && nxt[p][ch] == q) {
                cnt[q] -= cnt[p];
                cnt[clone] += cnt[p];
                nxt[p][ch] = clone;
                p = link[p];
            }
            link[q] = link[cur] = clone;
        }
    }

    ans += cnt[cur];
 
    return nxt[last][ch];
}

int get_rnk(int a, int b) {
    if (lab.count(pi {a, b }) == 0) {
        lab[pi {a, b}] = vs++;
    }
    return lab[pi {a, b}];
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> s; s.push_back('#');
    sa_init();

    for (int i = 0; i < n; ++i) h[i+1] = h[i] + (s[i] == '(') - (s[i] == ')');

    iota(near, near+n+1, 0);

    vector<int> tt;

    for (int i = n - 1; i--; ) {
        if (s[i] == ')') continue;

        int j = near[i+1];
        if (s[j] == ')') {
            near[i] = near[j+1];
            fst[j+1] = 1;
            rnk[i] = get_rnk(rnk[i+1], rnk[j+1]);
            srnk[i] = get_rnk(rnk[i+1], 0);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (fst[i] || near[i] == i) continue;

        const int j = near[i];
        int last = 0;
        // cout << "Push:";
        for (int t = i; t < j; t = near[t+1]+1) {
            last = sa_push(last, srnk[t]);
            // cout << ' ' << srnk[t];
        }
        // cout << " -> " << last << endl;
        tt.push_back(last);
    }

    cout << ans << '\n';
}