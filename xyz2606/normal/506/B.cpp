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
using namespace std;
const int N(111111);
vector<int> edges[N];
bool f[N];
int vst[N], rela[N];
int getr(int x) {
    int p(x), p1, p2;
    while(p != rela[p]) {
        p = rela[p];
    }
    p1 = p; p = x;
    while(p != rela[p]) {
        p2 = rela[p];
        rela[p] = p1;
        p = p2;
    }
    return p1;
}
vector<pair<int, int> > st0;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i(1); i <= n; i++) {
        rela[i] = i;
    }
    for(int i(1); i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        edges[x].push_back(y);
        rela[getr(x)] = getr(y);
    }
    fill(f + 1, f + 1 + n, false);
    fill(vst + 1, vst + 1 + n, false);
    for(int i(1); i <= n; i++) {
        if(!vst[i]) {
            vst[i] = i;
            bool flag(false);
            st0.push_back(make_pair(i, 0));
            while(!st0.empty()) {
                int v(st0.back().first), p(st0.back().second++);
                if(p != (int)edges[v].size()) {
                    int y(edges[v][p]);
                    //printf("%d %d %d\n", v, y, p);
                    if(!vst[y]) {
                        vst[y] = i;
                        st0.push_back(make_pair(y, 0));
                    }else if(vst[y] == i) {
                        flag = true;
                        st0.clear();
                        break;
                    }
                }else {
                    st0.pop_back();
                    vst[v] = N + 1;
                }
            }
            //printf("%d %d\n", i, flag);
            if(flag) {
                f[getr(i)] = true;
            }
        }
    }
    int ans(n);
    for(int i(1); i <= n; i++) {
        ans -= getr(i) == i && !f[i];
    }
    printf("%d\n", ans);
    fclose(stdin);
    return 0;
}