#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

    int st[400013];
    int size;
    int left(int w) { return w<<1; }
    int right(int w) { return (w<<1)+1; }
    int queryI(int w, int L, int R, int a, int b) {
        if (a>R || b<L) return 2147483647;
        if (L>=a && R<=b) return st[w];
        int lC = queryI(left(w),L,(L+R)/2,a,b);
        int rC = queryI(right(w),(L+R)/2+1,R,a,b);
        return min(lC,rC);
    }
    void updateI(int w, int L, int R, int a, int val) {
        if (a>R || a<L) return;
        if (L==R) st[w] = val;
        else {
            updateI(left(w),L,(L+R)/2,a,val);
            updateI(right(w),(L+R)/2+1,R,a,val);
            st[w] = min(st[left(w)],st[right(w)]);
        }
    }

    int query(int a, int b) { return queryI(1,0,size-1,a,b); }
    void update(int a, int val) { updateI(1,0,size-1,a,val); }

struct Query { int id,x1,x2,y1,y2; };

int n,m,k,q;
vector<int> rooks[100013];
vector<int> rooks2[100013];
vector<Query> queries[100013];
vector<Query> queries2[100013];
int ans[200013];

int main() {
    int n,m,k,q;
    scanf("%d%d%d%d",&n,&m,&k,&q);
    for (int i=0;i<k;i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        rooks[x].push_back(y);
        rooks2[y].push_back(x);
    }
    for (int i=0;i<q;i++) {
        int x1,x2,y1,y2;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        Query next;
        next.id = i; next.x1 = x1; next.x2 = x2; next.y1 = y1; next.y2 = y2;
        queries[x2].push_back(next);
        next.id = i; next.x1 = y1; next.x2 = y2; next.y1 = x1; next.y2 = x2;
        queries2[y2].push_back(next);
    }
        fill(st,st+4*(m+1),0);
        size = m+1;
    for (int i=1;i<=n;i++) {
        for (int j=0;j<rooks[i].size();j++) update(rooks[i][j],i);
        for (int j=0;j<queries[i].size();j++) {
            Query cur = queries[i][j];
            if (query(cur.y1,cur.y2)>=cur.x1) ans[cur.id] = 1;
        }
    }
    swap(rooks,rooks2); swap(queries,queries2);
        fill(st,st+4*(n+1),0);
        size = n+1;
    for (int i=1;i<=m;i++) {
        for (int j=0;j<rooks[i].size();j++) update(rooks[i][j],i);
        for (int j=0;j<queries[i].size();j++) {
            Query cur = queries[i][j];
            if (query(cur.y1,cur.y2)>=cur.x1) ans[cur.id] = 1;
        }
    }
    for (int i=0;i<q;i++) printf("%s\n",ans[i] ? "YES" : "NO");

    return 0;
}