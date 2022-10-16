#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

const int N = 3e5;
const int MOD = 998244353;

int t, n, m;
vector<vector<int>> mv;

long long pow2(int p) {
    if(p == 0) return 1LL;
    long long a = pow2(p/2); a *= a; a %= MOD;
    if(p % 2) a = (a*2) % MOD;
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int T = 1;
    for(cin >> t; t--; ++T) {
        cin >> n >> m;
        for(mv.resize(n), mv.clear(); m--; ) {
            int a, b;
            cin >> a >> b;
            mv[a-1].push_back(b-1);
            mv[b-1].push_back(a-1);
        }

        auto x = 1LL;
        vector<int> u(n, 0);
        bool ok = true;

        for(int i = 0; i < n && ok; ++i) {
            if(u[i] != 0) continue;

            int k = 0, z = 0;
            u[i] = 1;
            stack<int> st; st.push(i);
            while(!st.empty() && ok) {
                int cur = st.top(); st.pop();
                if(u[cur] == 1) ++k;
                ++z;

                for(int to : mv[cur]) {
                    if(u[to] == u[cur]) {
                        ok = false;
                        break;
                    }

                    if(u[to] == 0) {
                        st.push(to);
                        u[to] = 3-u[cur];
                    }
                }
            }


            auto p = (pow2(k) + pow2(z-k)) % MOD;
            x = (x * p) % MOD;
        }

        cout << (ok ? x : 0) << endl;
    }
}