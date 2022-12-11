#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 10;
const int verN = 2e4 + 10;

int n;
string s[2][N];
string pat;


struct graph{
    int n;
    int num[verN], low[verN];
    int ans[verN];
    vector<int> adj[verN];
    stack<int> st;

    void init(int n) {
        this->n = n;
    }
    void addEdge(int u, int v) {
        //cout << u << " imply " << v << '\n';
        adj[u].push_back(v);
    }
    bool conclude(int u, int val) {
        if (ans[u] * val < 0) return 0;
        ans[u] = val;
        ans[u ^ 1] = -val;
        return 1;
    }

    bool DFS(int u) {
        static int n1 = 0;
        num[u] = low[u] = ++n1;
        
        st.push(u);

        for(auto v : adj[u]) {
            if (num[v] < 0) continue;
            if (!num[v]) {
                if (!DFS(v)) return 0;
                low[u] = min(low[u], low[v]);
            } else low[u] = min(low[u], num[v]);
        }
        if (low[u] >= num[u]) {
            vector<int> scc;
            while (1) {
                int v = st.top(); st.pop();
                scc.push_back(v);
                if (v == u) break;
            }
            //cout << "Stongly\n";
            //for(auto i : scc) cout << i << " ";
            //cout << '\n';
            int need = 0;
            for(auto i : scc) {
                if (need == 0) need = ans[i]; 
                if (need * ans[i] < 0) return 0;
            }
            if (need == 0) need = 1;
            for(auto i : scc) {
                if (!conclude(i, need)) return 0;
            }
            for(auto i : scc) num[i] = -1;
        }
        return 1;
    }

    bool answer() {
        memset(ans, 0, sizeof(ans));
        for(int i = 0; i < n; i++) if (!num[i]) {
            if (!DFS(i)) return 0;
            //for(int j = 0; j < n; j++) cout << ans[j] << " ";
            //cout << '\n';
        }
        for(int u = 0; u < n; u++) if (ans[u] == 1) {
            for(auto v : adj[u]) {
                assert(ans[v] == 1);
            }
        }
        return 1;
    }
}mGraph;
void addEdge(int u, int v) {
    mGraph.addEdge(u, v);
}
int main() {
    cin >> n;
    for(int j = 0; j <= 1; j++) 
        for(int i = 0; i < n; i++) cin >> s[j][i];
    cin >> pat;
    
    mGraph.init(4 * n);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if (s[0][i][j] == s[1][i][j]) {
                if (pat[i] == '0') {
                    if (pat[j] == '1') {
                        addEdge(2 * i, 2 * i + 1);
                    }
                } else {
                    if (pat[j] == '0') {
                        int u = n + j;
                        addEdge(2 * u, 2 * u + 1);
                    } else {
                        int u = i, v = n + j;
                        for(int id = 0; id <= 1; id++) {
                            addEdge(2 * u + id, 2 * v + id);
                            addEdge(2 * v + id, 2 * u + id);
                        }
                    }
                }
            } else {
                if (pat[i] == '0') {
                    if (pat[j] == '0') {
                        cout << -1;
                        return 0;
                    } else {
                        int u = i;
                        addEdge(2 * u + 1, 2 * u);
                    }
                } else {
                    if (pat[j] == '0') {
                        int u = n + j;
                        addEdge(2 * u + 1, 2 * u);
                    } else {
                        int u = i, v = n + j;
                        for(int id = 0; id <= 1; id++) {
                            addEdge(2 * u + id, 2 * v + 1 - id);
                            addEdge(2 * v + id, 2 * u + 1 - id);
                        }
                    }
                }
            }
        }
    if (!mGraph.answer()) {
        cout << -1;
        return 0;
    }
    int ansn = 0;
    for(int i = 0; i < 2 * n; i++) ansn += (mGraph.ans[i * 2] == 1); 

    cout << ansn << '\n';
    for(int i = 0; i < 2 * n; i++) if (mGraph.ans[2 * i] == 1) {
        cout << (i < n ? "row " : "col ") << i % n << '\n';
    }
}