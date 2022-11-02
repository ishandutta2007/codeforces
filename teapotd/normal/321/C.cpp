#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for (int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())

struct Vert {
    Vi E;
    char label{0};
    int seen{0}, size;
};

vector<Vert> G;
int cnt;

void dfsSize(int v) {
    G[v].seen = cnt;
    G[v].size = 1;

    each(e, G[v].E) {
        if (G[e].seen != cnt && !G[e].label) {
            dfsSize(e);
            G[v].size += G[e].size;
        }
    }
}

void solve(int v, char chr) {
    cnt++;
    dfsSize(v);
    int p = -1;
    int n = G[v].size;

    while (true) {
        bool ok = 1;
        each(e, G[v].E) {
            if (G[e].seen == cnt && p != e && G[e].size >= n/2) {
                p = v;
                v = e;
                ok = 0;
                break;
            }
        }
        if (ok) break;
    }

    G[v].label = chr;
    each(e, G[v].E) {
        if (!G[e].label) {
            solve(e, chr+1);
        }
    }
}

int main() {
    cin.sync_with_stdio(0);
    cout << fixed << setprecision(15);

    int n; cin >> n;
    G.resize(n);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        G[a-1].E.pb(b-1);
        G[b-1].E.pb(a-1);
    }

    solve(0, 'A');
    each(v, G) {
        cout << v.label << ' ';
    }
    cout << '\n';
    return 0;
}