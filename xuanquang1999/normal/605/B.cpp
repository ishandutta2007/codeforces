//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
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

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct edge {
    int w, z, id;
    inline bool operator < (const edge &b) const {
        return ((w < b.w) || (w == b.w && z > b.z));
    }
};

int n, m, t, cur_e;
ll wTree;
edge e[maxN];
ii ans[maxN];
vector<ii> pos_edge;


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) scanf("%d%d", &e[i].w, &e[i].z), e[i].id = i;

    //0: choose
    sort(e+1, e+m+1);

    t = 1;
    fto(i, 1, m) {
        if (e[i].z == 1) {
            ++t; ans[e[i].id] = mp(t-1, t);
            fto(j, 1, t-2) {
                if (pos_edge.size() == m) break;
                pos_edge.pb(mp(j, t));
            }
        }
        else if (cur_e == pos_edge.size()) {
            puts("-1");
            return 0;
        }
        else ans[e[i].id] = pos_edge[cur_e++];
    }

    fto(i, 1, m) printf("%d %d\n", ans[i].ff, ans[i].ss);


    return 0;
}