#include <cstdio>
#include <algorithm>

using namespace std;

class ST {
private:
    int st[400013];
    int lazy[400013];
    int size;
    int left(int w) { return w<<1; }
    int right(int w) { return (w<<1)+1; }
    void process(int w, int L, int R) {
        st[w] = max(st[w],lazy[w]);
        if (L!=R) {
            lazy[left(w)] = lazy[w];
            lazy[right(w)] = lazy[w];
        }
        lazy[w] = 0;
    }
    int queryI(int w, int L, int R, int a, int b) {
        if (a>R || b<L) return -1;
        if (lazy[w]) process(w,L,R);
        if (L>=a && R<=b) return st[w];
        int lC = queryI(left(w),L,(L+R)/2,a,b);
        int rC = queryI(right(w),(L+R)/2+1,R,a,b);
        return max(lC,rC);
    }
    void updateI(int w, int L, int R, int a, int b, int val) {
        if (a>R || b<L) return;
        if (lazy[w]) process(w,L,R);
        if (L>=a && R<=b) {
            lazy[w] = val;
            process(w,L,R);
        } else {
            updateI(left(w),L,(L+R)/2,a,b,val);
            updateI(right(w),(L+R)/2+1,R,a,b,val);
            st[w] = max(st[left(w)],st[right(w)]);
        }
    }

public:
    ST(int s) {
        fill(st,st+4*s,-1);
        fill(lazy,lazy+4*s,0);
        size = s;
    }
    int query(int a, int b) { return queryI(1,0,size-1,a,b); }
    void update(int a, int b, int val) { updateI(1,0,size-1,a,b,val); }
};

int main() {
    int n;
    scanf("%d",&n);
    ST lastGreater(n+1);
    ST diesIn(n+1);
    int ans = 0;
    for (int i=1;i<=n;i++) {
        int next;
        scanf("%d",&next);
        int where = lastGreater.query(next,next);
        if (where!=-1) {
            if (where==i-1) {
                diesIn.update(i,i,1);
                ans = max(ans,1);
            } else {
                int time = diesIn.query(where+1,i-1)+1;
                ans = max(ans,time);
                diesIn.update(i,i,time);
            }
        }
        lastGreater.update(0,next-1,i);
    }
    printf("%d\n",ans);

    return 0;
}