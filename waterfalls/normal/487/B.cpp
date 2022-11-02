#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

class ST {
private:
    int st[400013];
    int size;

    int left(int w) { return w<<1; }
    int right(int w) { return (w<<1)+1; }
    int queryI(int w, int L, int R, int a, int b) {
        if (a>R || b<L) return -2147483647;
        if (L>=a && R<=b) return st[w];
        int lC = queryI(left(w),L,(L+R)/2,a,b);
        int rC = queryI(right(w),(L+R)/2+1,R,a,b);
        return max(lC,rC);
    }
    void updateI(int w, int L, int R, int a, int val) {
        if (a>R || a<L) return;
        if (L==R) st[w] = val;
        else {
            updateI(left(w),L,(L+R)/2,a,val);
            updateI(right(w),(L+R)/2+1,R,a,val);
            st[w] = max(st[left(w)],st[right(w)]);
        }
    }

public:
    ST(int s) {
        fill(st,st+4*s,-2147483647);
        size = s;
    }
    int query(int a, int b) { return queryI(1,0,size-1,a,b); }
    void update(int a, int val) { updateI(1,0,size-1,a,val); }
};

int n,s,l;
int a[100000];
int g[100000];
ST maxA(0);
ST minA(0);
ST f(0);

int main() {
    scanf("%d%d%d",&n,&s,&l);
    maxA = ST(n);
    minA = ST(n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) {
        maxA.update(i,a[i]);
        minA.update(i,-a[i]);
    }
    g[0] = 1;
    for (int i=1;i<n;i++) {
        g[i] = g[i-1]+1;
        while (maxA.query(i-g[i]+1,i)+minA.query(i-g[i]+1,i)>s) g[i]-=1;
    }
    f = ST(n+1);
    f.update(0,0);
    for (int i=1;i<=n;i++) {
        if (i<l || g[i-1]<l) f.update(i,-1000000000);
        else f.update(i,-1+f.query(i-g[i-1],i-l));
    }
    int ans = -f.query(n,n);
    printf("%d\n",ans>n ? -1 : ans);

    return 0;
}