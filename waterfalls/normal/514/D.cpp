#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class ST {
private:
    int st[400013];
    int size;
    int left(int w) { return w<<1; }
    int right(int w) { return (w<<1)+1; }
    int queryI(int w, int L, int R, int a, int b) {
        if (a>R || b<L) return 0;
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
    ST(int s=0) {
        fill(st,st+4*s,0);
        size = s;
    }
    int query(int a, int b) { return queryI(1,0,size-1,a,b); }
    void update(int a, int val) { updateI(1,0,size-1,a,val); }
};

int n,m,k;
int details[100013][5];
ST tree[5];
int howMany[5];

bool check(int len) {
    bool found = false;
    for (int i=0;i+len<=n;i++) {
        int cur = 0;
        for (int j=0;j<m;j++) {
            howMany[j] = tree[j].query(i,i+len);
            cur+=howMany[j];
            if (cur>k) break;
        }
        if (cur<=k) {
            found = true;
            break;
        }
    }
    return found;
}

int main() {
    scanf("%d%d%d",&n,&m,&k);
    for (int i=0;i<m;i++) tree[i] = ST(n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<m;j++) {
            scanf("%d",&details[i][j]);
            tree[j].update(i,details[i][j]);
        }
    }
    int low = 0;
    int high = n+1;
    while (high-low>1) {
        int mid = (low+high)/2;
        if (check(mid)) low = mid;
        else high = mid;
    }
    check(low);
    for (int i=0;i<m;i++) printf("%d ",howMany[i]);
    printf("\n");

    return 0;
}