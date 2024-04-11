#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int h[200013];
long long sumsL[200013];
long long sumsR[200013];

class ST {
private:
    long long st[800013];
    int size,type;
    int left(int w) { return w<<1; }
    int right(int w) { return (w<<1)+1; }
    void build(int w, int L, int R) {
        if (L==R) st[w] = (type ? sumsR[L]+h[L] : sumsL[L]+h[L]);
        else {
            build(left(w),L,(L+R)/2);
            build(right(w),(L+R)/2+1,R);
            st[w] = max(st[left(w)],st[right(w)]);
        }
    }
    long long queryI(int w, int L, int R, int a, int b) {
        if (a>R || b<L) return 0;
        if (L>=a && R<=b) return st[w];
        long long lC = queryI(left(w),L,(L+R)/2,a,b);
        long long rC = queryI(right(w),(L+R)/2+1,R,a,b);
        return max(lC,rC);
    }
    void updateI(int w, int L, int R, int a, long long val) {
        if (a>R || a<L) return;
        if (L==R) st[w] = val;
        else {
            updateI(left(w),L,(L+R)/2,a,val);
            updateI(right(w),(L+R)/2+1,R,a,val);
            st[w] = max(st[left(w)],st[right(w)]);
        }
    }

public:
    ST(int s=0, int t=0) {
        fill(st,st+4*s,0);
        size = s;
        type = t;
        if (size) build(1,0,size-1);
    }
    long long query(int a, int b) { return queryI(1,0,size-1,a,b); }
    void update(int a, long long val) { updateI(1,0,size-1,a,val); }
};

ST tree1;
ST tree2;
int d[200013];

long long solve(int L, int R, int divide) {
    long long r = d[divide];
    r+=tree2.query(L,divide)-sumsR[divide];
    r+=tree1.query(divide+1,R)-sumsL[divide+1];
    return r;
}

class ST2 {
private:
    int size;
    long long st[800013];
    int left(int w) { return w<<1; }
    int right(int w) { return (w<<1)+1; }
    void build(int w, int L, int R) {
        if (L!=R) {
            build(left(w),L,(L+R)/2);
            build(right(w),(L+R)/2+1,R);
            st[w] = max(st[left(w)],st[right(w)]);
            long long both = solve(L,R,(L+R)/2);
            st[w] = max(st[w],both);
        }
    }
    long long queryI(int w, int L, int R, int a, int b) {
        if (a>R || b<L) return 0;
        if (L>=a && R<=b) return st[w];
        long long lC = queryI(left(w),L,(L+R)/2,a,b);
        long long rC = queryI(right(w),(L+R)/2+1,R,a,b);
        long long both = 0;
        if ((L+R)/2>=a && (L+R)/2<=b) both = solve(max(a,L),min(b,R),(L+R)/2);
        return max(both,max(lC,rC));
    }
public:
    ST2(int s=0) {
        size = s;
        fill(st,st+4*size,0);
        if (size) build(1,0,size-1);
    }
    long long query(int a, int b) { return queryI(1,0,size-1,a,b); }
};

int n,m;
ST2 ans;

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf("%d",&d[i]);
    for (int i=0;i<n;i++) scanf("%d",&h[i]);
    for (int i=n;i<2*n;i++) d[i] = d[i-n], h[i] = h[i-n];
    for (int i=0;i<2*n;i++) h[i]*=2;
    for (int i=1;i<=2*n;i++) sumsL[i] = sumsL[i-1]+d[i-1];
    for (int i=2*n-1;i>=0;i--) sumsR[i] = sumsR[i+1]+d[i];
    tree1 = ST(2*n,0);
    tree2 = ST(2*n,1);
    ans = ST2(2*n);
    for (int i=0;i<m;i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a-=1; b-=1;
        if (a>b) b+=n;
        printf("%I64d\n",ans.query(b+1,a+n-1));
    }

    return 0;
}