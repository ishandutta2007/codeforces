using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005

int w, h, n;
pair<char, int> q[maxN];
int V[maxN], nV, prevV[maxN], nextV[maxN];
int H[maxN], nH, prevH[maxN], nextH[maxN];
ll curH, curV;
ll ans[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d\n", &w, &h, &n);

    fto(i, 0, n-1) cin >> q[i].fi >> q[i].se;

    H[0] = 0; nH = 1;
    V[0] = 0; nV = 1;
    fto(i, 0, n-1)
        if (q[i].fi == 'H') {
            H[nH] = q[i].se; ++nH;
        }
        else {
            V[nV] = q[i].se; ++nV;
        }
    H[nH] = h; ++nH;
    V[nV] = w; ++nV;

    sort(H, H+nH);
    sort(V, V+nV);

    fto(i, 1, nH-2) {
        prevH[H[i]] = H[i-1];
        nextH[H[i]] = H[i+1];
    }
    fto(i, 1, nV-2) {
        prevV[V[i]] = V[i-1];
        nextV[V[i]] = V[i+1];
    }

    fto(i, 1, nH-1) curH = max(curH, (ll)(H[i]-H[i-1]));
    fto(i, 1, nV-1) curV = max(curV, (ll)(V[i]-V[i-1]));

    fdto(i, n-1, 0) {
        ans[i] = curH*curV;
        int x = q[i].se;
        if (q[i].fi == 'H') {
            curH = max(curH, (ll)(nextH[x]-prevH[x]));
            prevH[nextH[x]] = prevH[x];
            nextH[prevH[x]] = nextH[x];
        }
        else {
            curV = max(curV, (ll)(nextV[x]-prevV[x]));
            prevV[nextV[x]] = prevV[x];
            nextV[prevV[x]] = nextV[x];
        }
    }

    fto(i, 0, n-1) cout << ans[i] << endl;

    return 0;
}