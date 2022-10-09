#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res, check1, a, b, c;
bool visited[100010];
vector<long long> adj[100010];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //ifstream cin("input.txt");
    //ofstream cout("output.txt");

    cin >> t;
    for (i1 = 0; i1 < t; i1++) {
        cin >> n;
        for (i = 1; i <= n; i++) {
            visited[i] = false;
            adj[i].clear();
            cin >> k;
            for (j = 0; j < k; j++) {
                cin >> a;
                adj[i].push_back(a);
            }
        }
        c = 0;
        for (i = 1; i <= n; i++) {
            check1 = 0;
            for (auto u : adj[i]) {
                //cout << u << endl;
                if (visited[u]) {
                    continue;
                }
                visited[u] = true;
                check1 = 1;
                break;
            }
            if (check1 == 0) {
                c = i;
            }
            //cout << i << ' ' << check1 << endl;
        }
        if (c == 0) {
            cout << "OPTIMAL" << endl;
        } else {
            for (j = 1; j <= n; j++) {
                if (visited[j] == false) {
                    break;
                }
            }
            cout << "IMPROVE" << endl << c << ' ' << j << endl;
        }
    }

    return 0;
}