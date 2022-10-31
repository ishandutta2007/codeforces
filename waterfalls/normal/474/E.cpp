#include <cstdio>
#include <algorithm>
#include <cmath>
#include <stack>

using namespace std;

class ST {
private:
    long long st[400013];
    long long lazy[400013];
    int size;
    int left(int w) { return w<<1; }
    int right(int w) { return (w<<1)+1; }
    void process(int w, int L, int R) {
        st[w] = max(st[w],lazy[w]);
        if (L!=R) {
            if (lazy[left(w)]) lazy[left(w)] = max(lazy[left(w)],lazy[w]);
            else lazy[left(w)] = lazy[w];
            if (lazy[right(w)]) lazy[right(w)] = max(lazy[right(w)],lazy[w]);
            else lazy[right(w)] = lazy[w];
        }
        lazy[w] = 0;
    }
    long long queryI(int w, int L, int R, int a, int b) {
        if (a>R || b<L) return -1000000000000000000;
        if (lazy[w]) process(w,L,R);
        if (L>=a && R<=b) return st[w];
        long long lC = queryI(left(w),L,(L+R)/2,a,b);
        long long rC = queryI(right(w),(L+R)/2+1,R,a,b);
        return max(lC,rC);
    }
    void updateI(int w, int L, int R, int a, int b, long long val) {
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
    ST(int s=0, long long init=0) {
        fill(st,st+4*s,init);
        fill(lazy,lazy+4*s,0);
        size = s;
    }
    long long query(int a) { return queryI(1,0,size-1,a,a); }
    long long query(int a, int b) { return queryI(1,0,size-1,a,b); }
    void update(int a, int b, long long val) { updateI(1,0,size-1,a,b,val); }
};

int n,d,k;
long long h[100000];
int len[100000];
ST lower,upper;
stack<int> print;

bool jump(long long a, long long b) { return abs(a-b)>=d; }

int main() {
    scanf("%d%d",&n,&d);
    for (int i=0;i<n;i++) scanf("%I64d",&h[i]);
    lower = ST(n+1,-10000000000000000);
    upper = ST(n+1,-10000000000000000);
    lower.update(0,0,10000000000000000);
    upper.update(0,0,10000000000000000);
    int k = 0;
    for (int i=0;i<n;i++) {
        int low = 0;
        int high = k+1;
        while (high-low>1) {
            int mid = (high+low)/2;
            if (jump(-lower.query(mid),h[i]) || jump(upper.query(mid),h[i])) low = mid;
            else high = mid;
        }
        low+=1;
        k = max(k,low);
        lower.update(0,low,-h[i]);
        upper.update(0,low,h[i]);
        len[i] = low;
    }
    printf("%d\n",k);
    int where = n-1;
    long long prev = -d-1;
    while (k>0 && where>=0) {
        if (len[where]==k && jump(prev,h[where])) {
            print.push(where+1);
            prev = h[where];
            k-=1;
        }
        where-=1;
    }
    while (print.size()>0) {
        printf("%d ",print.top());
        print.pop();
    }
    printf("\n");

    return 0;
}