#include <cstdio>
#include <vector>
using namespace std;

struct BS {
    unsigned long long D[1563] = {0,};
    void set(int i) {
        D[i>>6] |= (1llu<<(i&63));
    }
    void unset(int i) {
        D[i>>6] &= ~(1llu<<(i&63));
    }
    int get(int i) {
        return (D[i>>6]>>(i&63))&1;
    }
};

vector<int> map[100001];

int getone(const struct BS &A) {
    for(int i=0; i<1563; i++) {
        if(A.D[i] != 0) {
            for(int u=0; u<64; u++) if((A.D[i]>>u)&1) {
                return (i<<6) + u;
            }
        }
    }
    return 100001;
}

int main() {
    int n, m, x, y;
    scanf("%d%d", &n, &m);
    for(int i=0; i<m; i++) {
        scanf("%d%d", &x, &y);
        x--; y--;
        map[x].push_back(y);
        map[y].push_back(x);
    }
    int ans = 0;
    BS con, yet;
    for(int i=0; i<1563; i++) yet.D[i] = ~0llu;
    // 1 : go with 0
    con.set(0);
    for(int T=0; T<n; T++) {
        // con[x] = 0
        int x;
        x = getone(con);
        if(x >= n) {
            ans ++;
            x = getone(yet);
        }
        
        yet.unset(x);
        con.unset(x);
        BS t;
        for(auto e: map[x]) {
            t.set(e);
        }
        for(int i=0; i<1563; i++)
            con.D[i] = (con.D[i] | ~t.D[i]) & yet.D[i];
    }
    printf("%d\n", ans);
    return 0;
}