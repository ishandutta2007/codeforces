#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int T; cin >> T;
    while (T--){
        int N; cin >> N;
        vector<int> d(N+1);
        for (int i = 1; i <= N; ++i){
            cin >> d[i];
        }
        vector<int> c(N+1);
        vector<int> ord(N);
        iota(ord.begin(), ord.end(), 1);
        sort(ord.begin(), ord.end(), [&](int i, int j){
            return d[i] > d[j];
        });

        auto qry = [&](int v) -> int {
            cout << "? " << v << '\n';
            cout.flush();
            int to; cin >> to;
            return to;
        };

        int T = 0;
        for (int v : ord){
            if (c[v]) continue;
            vector<int> cc = {v};
            int col = -1;
            for (int i = 0; i < d[v]; ++i){
                int to = qry(v);
                cc.push_back(to);
                if (c[to]){
                    col = c[to];
                    break;
                }
            }
            if (col == -1) col = ++T;
            for (int x : cc) c[x] = col;
        }
        cout << "! ";
        for (int i = 1; i <= N; ++i){
            cout << c[i] << " ";
        }
        cout << '\n';
        cout.flush();
    }
}