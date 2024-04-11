#include <cstdio>
#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

int n,m,q;
unordered_map<int,int> p[100000];
unordered_map<int,int> h[100000];
unordered_map<int,int> mem[100000];

int findSet(int x, int c) { return p[x][c]==x ? x : p[x][c] = findSet(p[x][c],c); }
void mergeSet(int a, int b, int c) {
    int r1 = findSet(a,c), r2 = findSet(b,c);
    if (r1!=r2) {
        if (h[r1][c]<h[r2][c]) p[r1][c] = r2;
        else if (h[r1][c]>h[r2][c]) p[r2][c] = r1;
        else p[r1][c] = r2, h[r2][c]+=1;
    }
}
bool sameSet(int a, int b, int c) { return findSet(a,c)==findSet(b,c); }

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a-=1; b-=1;
        if (!p[a].count(c)) p[a][c] = a, h[a][c] = 0;
        if (!p[b].count(c)) p[b][c] = b, h[b][c] = 0;
        mergeSet(a,b,c);
    }
    scanf("%d",&q);
    for (int i=0;i<q;i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        u-=1; v-=1;
        if (p[u].size()>p[v].size()) swap(u,v);
        if (!mem[u].count(v)) {
            int ans = 0;
            for (unordered_map<int,int>::iterator it=p[u].begin();it!=p[u].end();it++) if (p[v].count(it->first) && sameSet(u,v,it->first)) ans+=1;
            mem[u][v] = ans;
        }
        printf("%d\n",mem[u][v]);
    }

    return 0;
}