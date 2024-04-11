#include <bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
typedef vector<int> vi;

const int maxn = 500006;

int n;
int tot;
int nxt[maxn];
int a[maxn];
vi e[maxn];
vi q;

void solve(int x) {
    for (auto i : e[x])
        solve(i);
    a[x] = ++tot;
}


int main() {
    int t;
    scanf( "%d", &t);
    while (t--) {
        scanf( "%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf( "%d", &nxt[i]);
            e[i].clear();
        }
        e[n+1].clear(); 
        q.clear();
        q.pb(n+1);
        bool flag = false;
        for (int i = n; i >= 1; --i) {
            if (nxt[i] == -1) nxt[i] = q.back();
            while (q.back() < nxt[i]) q.pop_back();
            if (q.back() != nxt[i]) {
                flag = true;
                break;
            }
            e[nxt[i]].pb(i);
            q.pb(i);
        }
        tot = 0;
        if (flag) puts("-1");
        else {
            solve(n + 1);
            for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
            puts("");
        }

    }
}