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
#define maxN 3005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, s, d[maxN][maxN], maxS;
vector<int> ke[maxN], ans;
vector<int> farthest_from[maxN], farthest_to[maxN];
bool visited[maxN];

void BFS(int s, int d[]) {
    queue<int> q;
    q.push(s);
    memset(visited, false, sizeof(visited));
    visited[s] = true;
    fto(u, 1, n) d[u] = -4*maxN;
    d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        forit(it, ke[u]) {
            int v = *it;
            if (!visited[v]) {
                visited[v] = true;
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v);
    }
    fto(u, 1, n) BFS(u, d[u]);
//    fto(u, 1, n) {
//        fto(v, 1, n) printf("%d ", d[u][v]);
//        puts("");
//    }

    fto(u, 1, n) {
        set<ii> s;
        fto(v, 1, n) {
            if (d[u][v] > 0) s.insert(mp(d[u][v], v));
        }
        fto(i, 0, 3) {
            if (s.empty()) break;
            farthest_to[u].pb(s.rbegin()->ss);
            s.erase(s.find(*s.rbegin()));
        }

        s.clear();
        fto(v, 1, n) {
            if (d[v][u] > 0) s.insert(mp(d[v][u], v));
        }
        fto(i, 0, 3) {
            if (s.empty()) break;
            farthest_from[u].pb(s.rbegin()->ss);
            s.erase(s.find(*s.rbegin()));
        }
    }
//    fto(u, 1, n) {
//        debug(u);
//        fto(i, 0, 3) printf("%d ", farthest_from[i]);
//        puts("");
//        fto(i, 0, 3) printf("%d ", farthest_to[i]);
//        puts("");
//    }

    fto(u, 1, n) {
        fto(v, 1, n) {
            if (u != v) {
                forit(it1, farthest_from[u]) {
                    int p = *it1;
                    if (p != v) {
                        forit(it2, farthest_to[v]) {
                            int q = *it2;
                            if (q != u && q != p) {
                                int t = d[p][u]+d[u][v]+d[v][q];
                                if (t > maxS) {
                                    maxS = t;
                                    ans.clear();
                                    ans.pb(p); ans.pb(u); ans.pb(v); ans.pb(q);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

//    debug(maxS);
    forit(it, ans) printf("%d ", *it);

    return 0;
}