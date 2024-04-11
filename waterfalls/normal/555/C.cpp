#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

struct Tri {
    int l,r,lastu,lastl;
    Tri(int x, int y, int a, int b) { l = x, r = y, lastl = a; lastu = b; }
};
class Comp {
public:
    bool operator() (Tri a, Tri b) {
        return a.l<b.l;
    }
};

int n,q;
set<int> taken;
set<Tri,Comp> tris;

int main() {
    scanf("%d%d",&n,&q);
    tris.insert(Tri(1,n,1,n));
    for (int i=0;i<q;i++) {
        int x;
        scanf("%d%*d",&x);
        char c;
        scanf(" %c",&c);
        if (taken.count(x)) {
            printf("0\n");
            continue;
        }
        Tri which = *(--tris.upper_bound(Tri(x,0,0,0)));
        tris.erase(which);
        if (c=='U') {
            printf("%d\n",which.lastu+1-x);
            if (x!=which.l) {
                tris.insert(Tri(which.l,x-1,which.lastl,which.lastu));
            }
            if (x!=which.r) {
                tris.insert(Tri(x+1,which.r,x+1,which.lastu));
            }
        } else {
            printf("%d\n",x+1-which.lastl);
            if (x!=which.l) {
                tris.insert(Tri(which.l,x-1,which.lastl,x-1));
            }
            if (x!=which.r) {
                tris.insert(Tri(x+1,which.r,which.lastl,which.lastu));
            }
        }
        taken.insert(x);
    }

    return 0;
}