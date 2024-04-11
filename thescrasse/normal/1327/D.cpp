#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, c[200010], s, boh;
bool visited[200010];
vector<long long> adj[200010];
vector<long long> st;
vector<long long> cy[200010];
vector<long long> cl;

void dfs(int s) {
    // cout << s << endl;
    if (visited[s]) {
        return;
    }
    visited[s] = true;
    for (auto u : adj[s]) {
        dfs(u);
    }
}

void dfsc(int st1, int s) {
    if (visited[s]) {
        return;
    }
    visited[s] = true;
    cy[st1].push_back(c[s]);
    for (auto u : adj[s]) {
        dfsc(st1, u);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        st.clear();
        cl.clear();
        cin >> n;
        for (i = 1; i <= n; i++) {
            adj[i].clear();
            cy[i].clear();
        }
        for (i = 1; i <= n; i++) {
            cin >> a;
            // cout << i << ' ' << a << endl;
            adj[i].push_back(a);
        }
        for (i = 1; i <= n; i++) {
            cin >> c[i];
        }
        for (i = 1; i <= n; i++) {
            visited[i] = false;
        }
        for (i = 1; i <= n; i++) {
            if (visited[i] == false) {
                // cout << "i " << i << endl;
                st.push_back(i);
                dfs(i);
            }
        }
        for (i = 1; i <= n; i++) {
            visited[i] = false;
        }
        for (auto u : st) {
            dfsc(u, u);
        }
        res = 1000000000010;
        for (auto u : st) {
            res = min(res, (long long)cy[u].size());
        }
        // cout << "r " << res << endl;
        for (auto u : st) {
            // cout << u << endl;
            s = cy[u].size();
            for (i = 1; i <= min(s, res); i++) {
                if (s % i == 0) {
                    for (j = 0; j < i; j++) {
                        check1 = 1;
                        for (k = j; k < s; k += i) {
                            if (cy[u][k] != cy[u][(k + i) % s]) {
                                // cout << "no " << k << ' ' << (k + i) % s << endl;
                                check1 = 0;
                                break;
                            }
                        }
                        if (check1 == 1) {
                            res = i;
                            break;
                        }
                    }
                }
            }
        }
        cout << res << endl;
    }

    return 0;
}