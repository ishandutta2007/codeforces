#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class ST {
private:
    int size;
    int st[2000013];
    int left(int w) { return (w<<1); }
    int right(int w) { return (w<<1)+1; }
    void updateI(int w, int L, int R, int a, int b, int v) {
        if (b<L || R<a) return;
        if (a<=L && R<=b) st[w] = v;
        else {
            updateI(left(w),L,(L+R)/2,a,b,v);
            updateI(right(w),(L+R)/2+1,R,a,b,v);
        }
    }
    int queryI(int w, int L, int R, int a) {
        if (a<L || R<a) return 0;
        if (L==R) return st[w];
        return max(st[w],max(queryI(left(w),L,(L+R)/2,a),queryI(right(w),(L+R)/2+1,R,a)));
    }
public:
    ST(int s=0) {
        size = s+1;
        fill(st,st+4*size,0);
    }
    void update(int a, int b, int v) { updateI(1,0,size-1,a,b,v); }
    int query(int a) { return queryI(1,0,size-1,a); }
};

class FT {
private:
    int size;
    long long ft[500013];
    void updateI(int a, int v) { while (a<=size) ft[a]+=v, a+=a&(-a); }
public:
    FT(int s=0) {
        size = s;
        fill(ft,ft+size+1,0);
    }
    void update(int a, int b, int v) {
        updateI(a,v);
        updateI(b+1,-v);
    }
    long long query(int a) {
        long long res = 0;
        while (a>0) res+=ft[a], a-=a&(-a);
        return res;
    }
};

#define MP make_pair
#define A first
#define B second
#define UU 0
#define MM 1

struct Query {
    char t;
    int a,b,v;
};
bool U(Query q) { return q.t=='U'; }
bool M(Query q) { return q.t=='M'; }
bool A(Query q) { return q.t=='A'; }
bool Z(Query q) { return q.t=='Z'; }
bool Q(Query q) { return q.t=='Q'; }

int n,m,counter;
Query q[500013];
vector<int> adj[2][500013];
bool gone[2][500013];
int id[2][500013];
pair<int,int> r[2][500013];
vector<int> need[500013];
ST tree;
FT tree2;
long long ans[500013];

void merge(int a, int b, int w) {
    r[w][a].A = min(r[w][a].A,r[w][b].A);
    r[w][a].B = max(r[w][a].B,r[w][b].B);
}

void dfs(int x, bool w) {
    id[w][x] = counter++;
    for (int i: adj[w][x]) dfs(i,w);
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=1;i<=m;i++) {
        scanf(" %c",&q[i].t);
        if (U(q[i])) scanf("%d%d",&q[i].a,&q[i].b);
        if (M(q[i])) scanf("%d%d",&q[i].a,&q[i].b);
        if (A(q[i])) scanf("%d",&q[i].v);
        if (Z(q[i])) scanf("%d",&q[i].v);
        if (Q(q[i])) scanf("%d",&q[i].v);
    }
    for (int i=1;i<=m;i++) {
        if (U(q[i])) {
            adj[UU][q[i].a].push_back(q[i].b);
            gone[UU][q[i].b] = 1;
        } else if (M(q[i])) {
            adj[MM][q[i].a].push_back(q[i].b);
            gone[MM][q[i].b] = 1;
        }
    }
    counter = 1;
    for (int i=1;i<=n;i++) if (!gone[UU][i]) dfs(i,UU);
    counter = 1;
    for (int i=1;i<=n;i++) if (!gone[MM][i]) dfs(i,MM);
    for (int w=0;w<2;w++) for (int i=1;i<=n;i++) r[w][i] = MP(id[w][i],id[w][i]);
    for (int i=1;i<=m;i++) {
        if (U(q[i])) merge(q[i].a,q[i].b,UU);
        else if (A(q[i])) q[i].a = r[UU][q[i].v].A, q[i].b = r[UU][q[i].v].B;
        if (M(q[i])) merge(q[i].a,q[i].b,MM);
        else if (Z(q[i])) q[i].a = r[MM][q[i].v].A, q[i].b = r[MM][q[i].v].B;
    }
    tree = ST(n);
    for (int i=1;i<=m;i++) {
        if (Z(q[i])) tree.update(q[i].a,q[i].b,i);
        if (Q(q[i])) {
            q[i].a = tree.query(id[MM][q[i].v]);
            need[q[i].a].push_back(i);
        }
    }
    tree2 = FT(n);
    for (int i=m;i>=0;i--) {
        if (A(q[i])) tree2.update(q[i].a,q[i].b,q[i].b-q[i].a+1);
        if (Q(q[i])) ans[i]-=tree2.query(id[UU][q[i].v]);
        for (int w: need[i]) ans[w]+=tree2.query(id[UU][q[w].v]);
    }
    for (int i=1;i<=m;i++) if (Q(q[i])) printf("%lld\n",ans[i]);

    return 0;
}