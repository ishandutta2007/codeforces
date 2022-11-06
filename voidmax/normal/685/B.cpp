#include <bits/stdc++.h>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <int, int>
#define x first
#define y second
#define files(FileName) read(FileName); write(FileName)
#define read(FileName) freopen((FileName + ".in").c_str(), "r", stdin)
#define write(FileName) freopen((FileName + ".out").c_str(), "w", stdout)

using namespace std;

string FileName = "input";

typedef long double base;

int n, m;
vector <int> edge[300001];
int ans[300001];
int P[300001];
int S[300001];

void dfs(int i, int p) {
    if (i == p) return;
    S[i] = 1;
    for(int j: edge[i]) {
        if (j == p) continue;
        dfs(j, i);
        S[i] += S[j];
    }
    P[i] = p;
    ans[i] = -1;
    for(int j: edge[i]) {
        if (j == p || S[j] < S[i] / 2) continue;
        int Id = ans[j];
        while (Id != i && (S[i] - S[Id] > S[i] / 2)) {
            Id = P[Id];
        }
        if (Id != i && (S[i] - S[Id] <= S[i] / 2)) {
            ans[i] = Id;
            break;
        }
    }
    if (ans[i] == -1) ans[i] = i;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    For(i, 1, n) {
        cin >> P[i]; --P[i];
        edge[i].pb(P[i]);
        edge[P[i]].pb(i);
    }
    dfs(0, -1);
    For(i, 0, m) {
        int L; cin >> L; --L;
        cout << ans[L] + 1 << endl;
    }
}