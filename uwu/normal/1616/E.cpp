#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

queue<int> pos[26];
struct Bit{
    vector<int> a;
    void init(int N){ a = vector<int>(N + 2, 0); }
    void ins(int i, int v){ for (++i; i < a.size(); i += i & -i) a[i] += v; }
    void inc(int l, int r){
        ins(l, 1); ins(r + 1, -1);
    }
    int qry(int i){
        int ret = 0;
        for (++i; i; i -= i & -i) ret += a[i];
        return ret;
    }
} bit;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        for (int i = 0; i < 26; ++i){
            while (!pos[i].empty()) pos[i].pop();
        }
        int N; cin >> N;
        bit.init(N);
        string s, t; cin >> s >> t;
        for (int i = 0; i < N; ++i) pos[s[i] - 'a'].push(i);
        ll ans = LLONG_MAX, cur = 0;
        for (int i = 0; i < N; ++i){
            for (int c = t[i] - 1; c >= 'a'; --c){
                if (pos[c - 'a'].empty()) continue;
                int idx = pos[c - 'a'].front(); idx += bit.qry(idx);
                ans = min(ans, cur + idx - i);
            }
            if (pos[t[i] - 'a'].empty()) break;
            int idx = pos[t[i] - 'a'].front();
            int tmp = idx;
            idx += bit.qry(idx);
            pos[t[i] - 'a'].pop();
            cur += idx - i;
            bit.inc(0, tmp);
        }
        cout << (ans == LLONG_MAX ? -1 : ans) << '\n';
    }
}