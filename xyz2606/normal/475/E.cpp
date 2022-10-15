#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<string>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<queue>
#include<bitset>
using namespace std;
vector<int> edges[2222], rev[2222], edges1[2222];
vector<bool> used[2222];
int color[2222], siz[2222], cnt[2222];
bool vst[2222];
bitset<2001> dp, dp1;
vector<pair<int, int> > st0;
vector<int> st1, st2;
void psh(int v) {
    st0.push_back(make_pair(v, 0));
    color[v] = st0.size();
    st1.push_back(v);
    st2.push_back(v);
}
int main() {
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i(1); i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        rev[x].push_back(edges[y].size());
        rev[y].push_back(edges[x].size());
        edges[x].push_back(y);
        used[x].push_back(false);
        used[y].push_back(false);
        edges[y].push_back(x);
    }
    int c(n);
    fill(color + 1, color + 1 + n, 0);
    for(int i(1); i <= n; i++) if(!color[i]) {
        psh(i);
        while(!st0.empty()) {
            int v(st0.back().first), p(st0.back().second++);
            if(p != (int)edges[v].size()) {
                if(!used[v][p]) {
                    used[v][p] = used[edges[v][p]][rev[v][p]] = true;
                    int y(edges[v][p]);
                    if(!color[y]) {
                        psh(y);
                    }else
                        while(!st2.empty() and color[st2.back()] > color[y])
                            st2.pop_back();
                }
            }else {
                st0.pop_back();
                if(st2.back() == v) {
                    st2.pop_back();
                    color[v] = ++c;
                    while(st1.back() != v) {
                        color[st1.back()] = c;
                        st1.pop_back();
                    }
                    st1.pop_back();
                }
            }
        }
    }
    //for(int i(1); i <= n; i++)
    //  printf("%d\n", color[i]);
    fill(cnt + 1, cnt + 1 + n, 0);
    for(int i(1); i <= n; i++) {
        cnt[color[i] - n] ++;
        for(int j(0); j < (int)edges[i].size(); j++)
            if(color[i] != color[edges[i][j]]) {
                //printf("%d %d %d %d\n", i, edges[i][j], color[i], color[edges[i][j]]);
                edges1[color[i] - n].push_back(color[edges[i][j]] - n);
                
            }
    }
    c -= n;
    for(int i(1); i <= c; i++)
        edges[i] = edges1[i];
    //for(int i(1); i <= c; i++) {
//      for(int j(0); j < (int)edges[i].size(); j++)
//          printf("%d %d\n", i, edges[i][j]);
//  }
    int ans(0);
    for(int i(1); i <= c; i++) {
        fill(vst + 1, vst + 1 + c, false);
        st0.push_back(make_pair(i, 0));
        fill(siz + 1, siz + 1 + c, 0);
        vst[i] = true;
        int ans1(0);
        while(!st0.empty()) {
            int v(st0.back().first), p(st0.back().second++);
            //printf("%d %d\n", v, edges[v][p]);
            if(p != (int)edges[v].size()) {
                if(!vst[edges[v][p]]) {
                    vst[edges[v][p]] = true;
                    st0.push_back(make_pair(edges[v][p], 0));
                }
            }else {
                siz[v] += cnt[v];
            //  printf("siz[%d] = %d\n", v, siz[v]);
                ans1 += cnt[v] * siz[v];
                st0.pop_back();
                if(!st0.empty()) {
                    siz[st0.back().first] += siz[v];
                }
            }
        }
        dp.reset();
        dp[0] = 1;
    //  printf("WoW %d\n", edges[i].size());
        for(int j(0); j < (int)edges[i].size(); j++) {
            int x(siz[edges[i][j]]);
            //printf("%d\n", x);
            dp1 = (dp << x) | (dp >> x);
            //printf("Such\n");
            for(int k(0); k < x; k++)
                if(dp[k])
                    dp1[x - k] = 1;
            dp = dp1;
        }
        //printf("oge\n");
        for(int j(0); j <= n; j++) {
            if(dp[j]) {
                ans = max(ans, ans1 + (n - cnt[i] + j) / 2 * (n - cnt[i] - j) / 2);
                break;
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}