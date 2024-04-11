#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, a) for(auto &i : (a))
#define SZ(x) ((int)(x).size())
#define X first
#define Y second
#define MP std::make_pair
#define PR std::pair
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

int n, m, k;
std::vector<VI> g;
VI C;
std::vector<int> col;
std::set<int> bad;

void dfs(int v, int cl=0){
        col[v] = cl;
        TRAV(ch, g[v]){
                assert(C[ch] == C[v]);
                if(col[ch] != -1){
                        if(col[ch] == col[v]){
                                bad.insert(C[v]);
                        }
                }else dfs(ch, 1-cl);
        }
}

std::vector<VI> gs;
VI ind;

VI WHERE;
void dfs2(int v, int cl=0){
        col[v] = cl;
        ind[v] = WHERE[cl];
        TRAV(ch, g[v]){
                if(col[ch] != -1){
                        assert(col[ch] != col[v]);
                }else dfs2(ch, 1-cl);
        }
}


bool BBB;
void dfs3(int v, int cl=0){
        col[v] = cl;
        TRAV(ch, gs[v]){
                if(col[v] == col[ch]) BBB = true;
                if(col[ch] == -1){
                        dfs3(ch, 1-cl);
                }
        }
}
void clean(int v){
        col[v] = -1;
        TRAV(ch, gs[v]){
                if(col[ch] != -1) clean(ch);
        }
}

int main(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);

        std::cin >> n >> m >> k;
        col.resize(n, -1);
        g.resize(n);
        C.resize(n);
        FOR(i, n){
                std::cin >> C[i];
                C[i]--;
        }
        std::vector<PII> edges;
        FOR(i, m){
                int a, b;
                std::cin >> a >> b;
                a--;b--;
                if(C[a] == C[b]){
                        g[a].push_back(b);
                        g[b].push_back(a);
                }else edges.push_back(MP(a, b));
        }

        FOR(i, n) if(col[i] == -1) dfs(i);
        std::vector<VI> my(k);

        FOR(i, n) my[C[i]].push_back(i);
        ind.resize(n);
        std::fill(col.begin(), col.end(), -1);
        FOR(grp, k){
                if(bad.count(grp)) continue;
                TRAV(i, my[grp]){
                        if(col[i] == -1){
                                gs.emplace_back();
                                gs.emplace_back();
                                gs[SZ(gs)-2].push_back(SZ(gs)-1);
                                gs[SZ(gs)-1].push_back(SZ(gs)-2);
                                WHERE = VI{SZ(gs)-2, SZ(gs)-1};
                                dfs2(i);
                        }
                }
        }

        auto make = [&](int a, int b){
                return MP(std::min(a, b), std::max(a, b));
        };

        std::map<PII, std::vector<PII> > map;
        TRAV(ed, edges){
                auto e = make(C[ed.X], C[ed.Y]);
                if(bad.count(e.X) || bad.count(e.Y)) continue;
                assert(e.X != e.Y);
                map[e].push_back(MP(ind[ed.X], ind[ed.Y]));
        }

        col = std::vector<int>(SZ(gs), -1);

        int cnt = 0;

        TRAV(pr, map){
                auto& vec = pr.Y;

                TRAV(ed, vec){
                        gs[ed.X].push_back(ed.Y);
                        gs[ed.Y].push_back(ed.X);
                }

                BBB = false;
                TRAV(ed, vec){
                        if(col[ed.X] == -1) dfs3(ed.X);
                        if(col[ed.Y] == -1) dfs3(ed.Y);
                }

                if(BBB) cnt++;

                TRAV(ed, vec){
                        clean(ed.X);
                        clean(ed.Y);
                }

                TRAV(ed, vec){
                        gs[ed.X].pop_back();
                        gs[ed.Y].pop_back();
                }
        }

        ll heh = 0;
        ll cur = k-1;
        FOR(i, SZ(bad)) heh += cur, cur--;
        std::cout << (1ll*k*(k-1)/2) - cnt - heh << "\n";


        return 0;
}