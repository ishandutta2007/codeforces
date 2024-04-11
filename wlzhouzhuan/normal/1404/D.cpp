#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 10;
vector<int> adj[MAXN];
int vi[MAXN], pv[MAXN];
vector<int> choices[2];

void dfs(int s, int x) {
    vi[s] = 1;
    choices[x].push_back(s);
    for(auto v : adj[s])
        if(!vi[v])
            dfs(v, x ^ 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    if(n % 2) {
        cout << "Second" << endl;
        for(int i = 1; i <= 2 * n; i++) {
            int x;
            cin >> x;
            if(pv[x]) {
                adj[pv[x]].push_back(i);
                adj[i].push_back(pv[x]);
            }
            else {
                pv[x] = i;
            }
        }
        for(int i = 1; i <= n; i++) {
            adj[i].push_back(n + i);
            adj[n + i].push_back(i);
        }
        for(int i = 1; i <= 2 * n; i++) {
            if(!vi[i])
                dfs(i, 0);
        }
        long long sum = 0;
        for(auto x : choices[0])
            sum += x;
        if(sum % (2 * n) != 0)
            swap(choices[0], choices[1]);
        for(auto x : choices[0])
            cout << x << " ";
        cout << endl;
        int res;
        cin >> res;
        //assert(res == 0);
        return 0;
    }
    else {
        cout << "First" << endl;
        for(int i = 0; i < 2 * n; i++)
            cout << (i % n) + 1 << " ";
        cout << endl;
        int res;
        cin >> res;
        //assert(res == 0);
        return 0;
    }
}