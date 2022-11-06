#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int p[200001];
void init_uf(int s) {
    for(int i=0; i<=s; i++) p[i] = i;
}
int P(int x) {
    if(p[x] == x) return x;
    return p[x] = P(p[x]);
}
void uni(int x, int y) {
    p[P(x)] = P(y);
}
vector<int> in[200001];
int chk[200001];
int main() {
    int n, m, q, s = 0;
    scanf("%d%d%d", &n, &m, &q);
    for(int i=0; i<q; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        in[x].emplace_back(y);
    }
    init_uf(m);
    for(int i=1; i<=n; i++) {
        for(int j=0; j<(int)in[i].size()-1; j++)
            uni(in[i][j], in[i][j+1]);
    }
    int ans = -1;
    for(int j=1; j<=m; j++) if(p[j] == j) ans++;
    for(int i=1; i<=n; i++) {
        if(in[i].size() == 0) ans++;
    }
    printf("%d\n", ans);
    return 0;
}