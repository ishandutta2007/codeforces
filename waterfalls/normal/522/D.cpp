#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

class ST {
private:
    int st[2000013];
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
public:
    ST(int s=0) {
        fill(st,st+4*s,2147483647);
        size = s;
    }
    int query(int a, int b) { return queryI(1,0,size-1,a,b); }
    void update(int a, int val) { updateI(1,0,size-1,a,val); }
};

int n,m;
map<int,int> last;
int next[500013];
pair<pair<int,int>,int> queries[500013];
int ans[500013];
ST tree;

int main() {
    scanf("%d%d",&n,&m);
    tree = ST(n);
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        if (last.count(a)) {
            tree.update(i,i-last[a]);
            next[last[a]] = i;
        }
        last[a] = i;
        next[i] = -1;
    }
    for (int i=0;i<m;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        l-=1; r-=1;
        queries[i] = make_pair(make_pair(l,r),i);
    }
    sort(queries,queries+m);
    int which = 0;
    for (int i=0;i<n;i++) {
        while (which<m && queries[which].first.first==i) {
            int cur = tree.query(i,queries[which].first.second);
            if (cur==2147483647) cur = -1;
            ans[queries[which].second] = cur;
            which+=1;
        }
        if (next[i]!=-1) tree.update(next[i],2147483647);
    }
    for (int i=0;i<m;i++) printf("%d\n",ans[i]);

    return 0;
}