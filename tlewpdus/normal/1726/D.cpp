#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 998244353;

int N, M;
vector<pii> lis[200100];
int vis[200100];
int dep[200100], pi[200100];
pii edge[200100];

vector<int> sup;
void dfs(int here, int p) {
    vis[here] = 1;
    dep[here] = (~p ? dep[p] : -1) + 1;
    for (pii &e : lis[here]) {
        int there = e.first;
        if (!vis[there]) {
            pi[there] = e.second;
            dfs(there, here);
        } else if (there != p && dep[there] > dep[here]) {
            sup.push_back(e.second);
        }
    }
}

int main() {
    int ttt;

    scanf("%d", &ttt);
    while (ttt--) {
        scanf("%d%d", &N, &M);
        for (int i = 0; i < M; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            --a;
            --b;
            lis[a].emplace_back(b, i);
            lis[b].emplace_back(a, i);
            edge[i] = {a, b};
        }
        sup.clear();
        for (int i = 0; i < N; i++) {
            dep[i] = -1;
        }
        dfs(0, -1);
        // for (int &j : sup) {
        //     printf("%d, %d\n", edge[j].first, edge[j].second);
        // }
        assert(sup.size() == M - N + 1);

        if (sup.size() == 3) {
            vector<int> chk(N, 0);
            for (int &j : sup) {
                chk[edge[j].first]++;
                chk[edge[j].second]++;
            }
            bool mang = true;
            for (int &j : sup) {
                if (chk[edge[j].first] != 2) mang = false;
                if (chk[edge[j].second] != 2) mang = false;
            }
            if (mang) {
                vector<int> tsup;
                tsup.push_back(sup[1]);
                tsup.push_back(sup[2]);
                if (dep[edge[sup[0]].first] > dep[edge[sup[0]].second])
                    tsup.push_back(pi[edge[sup[0]].first]);
                else
                    tsup.push_back(pi[edge[sup[0]].second]);
                for (int i = 0; i < M; i++) {
                    bool in = false;
                    for (int &j : tsup) {
                        if (i == j) in = true;
                    }
                    printf("%d", (int)in);
                }
                puts("");

            } else {
                for (int i = 0; i < M; i++) {
                    bool in = false;
                    for (int &j : sup) {
                        if (i == j) in = true;
                    }
                    printf("%d", (int)in);
                }
                puts("");
            }
        } else {
            for (int i = 0; i < M; i++) {
                bool in = false;
                for (int &j : sup) {
                    if (i == j) in = true;
                }
                printf("%d", (int)in);
            }
            puts("");
        }

        for (int i = 0; i < N; i++) {
            vis[i] = 0;
            lis[i].clear();
        }
    }

    return 0;
}