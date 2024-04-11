using namespace std;

#include<bits/stdc++.h>
#define maxN 100005
#define oo 1000000000009

vector<pair<int, int> > ke[maxN];

int n, m, trace[maxN], s, t;
long long d[maxN];

void dijsktra() {
    set<pair<long long, int> > sii;

    for (int i=1; i<=n; ++i) d[i] = oo;
    d[s] = 0;

    for (int i=1; i<=n; ++i) trace[i] = 0;
    trace[s] = s;
    sii.insert(make_pair(d[s], s));

    while (!sii.empty()) {
        int u = sii.begin()->second;
        sii.erase(sii.begin());
        //printf("%d %d\n", d[u], u);
        for (int i=0; i<ke[u].size(); ++i) {
            int v = ke[u][i].first, w = ke[u][i].second;
            //printf("%d %d %d\n", i, v, w);
            if (d[v] > d[u] + w) {
                //printf("%d %d %d\n", i, v, w);
                sii.erase(make_pair(d[v], v));
                d[v] = d[u] + w;
                trace[v] = u;
                sii.insert(make_pair(d[v], v));
            }

        }
    }
}

int main() {

    //freopen("input.txt", "r", stdin);

    cin >> n >> m;
    s = 1;
    t = n;
    for (int i=1; i<=m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        ke[u].push_back(make_pair(v, w));
        ke[v].push_back(make_pair(u, w));
    }

    dijsktra();

    if (d[t] == oo) puts("-1");
    else {
        int v = t;
        vector<int> ans;
        ans.push_back(t);
        while (v != s) {
            int u = trace[v];
            ans.push_back(u);
            v = u;
        }
        for (vector<int>::reverse_iterator rit = ans.rbegin(); rit != ans.rend(); ++rit) cout << *rit << " ";
    }
}