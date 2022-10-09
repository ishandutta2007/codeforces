// 1305D
// trovare root di un tree in floor(n / 2) query in cui si riceve il lca di due nodi a scelta
// idee: prendo sempre due foglie

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, check1, a, b, c, l, v[2], degr[1010];
bool u[1010];
vector<long long> adj[1010];
queue<long long> q;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> n;
    for (i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degr[a]++;
        degr[b]++;
    }

    for (i = 1; i <= n; i++) {
        if (degr[i] == 1) {
            q.push(i);
            u[i] = true;
        }
    }

    while (q.size() >= 2) {
        v[0] = q.front();
        q.pop();
        v[1] = q.front();
        q.pop();
        cout << "? " << v[0] << " " << v[1] << endl;
        cout.flush();
        cin >> l;
        if (l == v[0] || l == v[1]) {
            cout << "! " << l << endl;
            return 0;
        }
        for (i1 = 0; i1 < 2; i1++) {
            a = v[i1];
            for (i = 0; i < adj[a].size(); i++) {
                if (adj[a][i] != -1) {
                    b = adj[a][i];
                    degr[b]--;
                    break;
                }
            }
            for (i = 0; i < adj[b].size(); i++) {
                if (adj[b][i] == a) {
                    adj[b][i] = -1;
                    break;
                }
            }
            if (degr[b] == 1) {
                q.push(b);
                u[b] = true;
            }
        }
    }

    cout << "! " << q.front() << endl;

    return 0;
}