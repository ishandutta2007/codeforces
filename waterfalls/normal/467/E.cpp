#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int far[500013];

class ST {
private:
    int st[2000013];
    int size;
    int left(int w) { return w<<1; }
    int right(int w) { return (w<<1)+1; }
    int queryI(int w, int L, int R, int a, int b) {
        if (a>R || b<L) return -1;
        if (L>=a && R<=b) return st[w];
        int lC = queryI(left(w),L,(L+R)/2,a,b);
        int rC = queryI(right(w),(L+R)/2+1,R,a,b);
        if (lC==-1) return rC;
        if (rC==-1) return lC;
        return far[lC]>far[rC] ? lC : rC;
    }
    void updateI(int w, int L, int R, int a) {
        if (a>R || a<L) return;
        if (L==R) st[w] = L;
        else {
            updateI(left(w),L,(L+R)/2,a);
            updateI(right(w),(L+R)/2+1,R,a);
            st[w] = far[st[left(w)]]>far[st[right(w)]] ? st[left(w)] : st[right(w)];
        }
    }
public:
    ST(int s=0) {
        fill(st,st+4*s,-1);
        size = s;
    }
    int query(int a, int b) { return queryI(1,0,size-1,a,b); }
    void update(int a) { updateI(1,0,size-1,a); }
};

int n;
int b[500013];
int a[500013];
map<int,int> compress;
vector<int> print;
vector<int> has[500013];
ST tree;

int main() {
    scanf("%d",&n);
    tree = ST(n);
    for (int i=0;i<n;i++) {
        scanf("%d",&b[i]);
        if (!compress.count(b[i])) compress[b[i]] = compress.size();
        a[i] = compress[b[i]];
    }
    int where = 0;
    int start = 0;
    while (where<n) {
        int found = -1;
        if (has[a[where]].size()>0 && has[a[where]][0]!=start) {
            int high = tree.query(start,has[a[where]][0]-1);
            if (high!=-1 && far[high]>has[a[where]][0]) found = high;
        }
        if (has[a[where]].size()==3) found = where;
        if (found!=-1) {
            print.push_back(b[found]); print.push_back(b[where]);
            for (int i=start;i<where;i++) has[a[i]].clear();
            start = where+1;
        } else {
            if (has[a[where]].size()>0) {
                far[has[a[where]][0]] = where;
                tree.update(has[a[where]][0]);
            }
            has[a[where]].push_back(where);
        }
        where+=1;
    }
    printf("%d\n",4*print.size()/2);
    for (int i=0;i<print.size();i+=2) printf("%d %d %d %d ",print[i],print[i+1],print[i],print[i+1]);
    printf("\n");

    return 0;
}