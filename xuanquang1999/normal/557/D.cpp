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
#define maxN 100005

ll n, m, cnt[3], one_edge_ans;
int c[maxN];
vector<int> ke[maxN];
bool is_bipartile, need_two_edge;

void DFS(int u, int cur) {
    //printf("%d %d\n", u, cur);
    //cout << is_bipartile;
    c[u] = cur; ++cnt[cur];
    forit(it, vector<int>, ke[u]) {
        int v = *it;
        if (c[v] == cur) is_bipartile = false;
        else if (c[v] == 0) DFS(v, 3-cur);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, m-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v);
        ke[v].pb(u);
    }

    is_bipartile = true;
    fto(u, 1, n)
        if (c[u] == 0) {
            cnt[1] = 0; cnt[2] = 0;
            DFS(u, 1);
            one_edge_ans+=(cnt[1]*(cnt[1]-1) + cnt[2]*(cnt[2]-1))/2;
        }

    if (!is_bipartile) printf("0 1");
    else if (m == 0) printf("3 %I64d", (n*(n-1)*(n-2))/6);
    else {
        need_two_edge = true;
        fto(u, 1, n)
            if (ke[u].size() > 1) {
                need_two_edge = false;
                break;
            }
        if (need_two_edge) printf("2 %I64d", m*(m-1)*2+(n-2*m)*m);
        else printf("1 %I64d", one_edge_ans);
    }


    return 0;
}