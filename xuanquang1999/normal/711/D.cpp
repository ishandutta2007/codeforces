//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005
#define MOD 1000000007

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, p[maxN], low[maxN], num[maxN], DFSCount;
bool avail[maxN];
stack<int> s;
vector<int> ke[maxN];
ll ans = 1, e2[maxN], inSCC;

void DFS(int u) {
    low[u] = num[u] = ++DFSCount;
    s.push(u);

    forit(it, ke[u]) {
        int v = *it;
        if (avail[v]) {
            if (!num[v]) {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
            else low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] >= num[u]) {
        int cnt = 0;

        while (s.top() != u) {
            avail[s.top()] = false;
            s.pop();
            ++cnt;
        }
        avail[s.top()] = false;
        ++cnt;
        s.pop();

        if (cnt > 1) {
            ans = (ans*(e2[cnt]-2+MOD))%MOD;
            inSCC += cnt;
        }
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);

    e2[0] = 1;
    fto(i, 1, n) e2[i] = (e2[i-1]*2)%MOD;

    fto(i, 1, n) {
        scanf("%d", &p[i]);
        ke[i].pb(p[i]);
    }
    memset(avail, true, sizeof avail);
    fto(u, 1, n) {
        if (avail[u]) {
            DFS(u);
        }
    }
    //debug(other);
    cout << (ans*e2[n-inSCC])%MOD << endl;

    return 0;
}