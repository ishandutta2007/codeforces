#include <cstdio>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (a>b) swap(a,b);
    if (a==0) return b;
    return gcd(a,b%a);
}

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
        return gcd(lC,rC);
    }
    void updateI(int w, int L, int R, int a, int val) {
        if (a>R || a<L) return;
        if (L==R) st[w] = val;
        else {
            updateI(left(w),L,(L+R)/2,a,val);
            updateI(right(w),(L+R)/2+1,R,a,val);
            st[w] = gcd(st[left(w)],st[right(w)]);
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

int n,t;
ST tree;
map<int,vector<int> > occurs;

int main() {
    scanf("%d",&n);
    tree = ST(n);
    for (int i=0;i<n;i++) {
        int s;
        scanf("%d",&s);
        tree.update(i,s);
        if (!occurs.count(s)) occurs[s] = vector<int>();
        occurs[s].push_back(i);
    }
    scanf("%d",&t);
    for (int i=0;i<t;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        l-=1; r-=1;
        int victor = tree.query(l,r);
        if (!occurs.count(victor)) printf("%d\n",r-l+1);
        else {
            int first = lower_bound(occurs[victor].begin(),occurs[victor].end(),l)-occurs[victor].begin();
            int last = lower_bound(occurs[victor].begin(),occurs[victor].end(),r+1)-occurs[victor].begin()-1;
            int winners = last-first+1;
            printf("%d\n",r-l+1-winners);
        }
    }

    return 0;
}