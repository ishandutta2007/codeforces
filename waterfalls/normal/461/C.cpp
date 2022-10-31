#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

class FT {
private:
    int size;
    int ft[100013];
public:
    FT(int s=0) {
        size = s;
        fill(ft,ft+s+1,0);
    }
    void update(int ind, int x) {
        ind+=1;
        while (ind<=size) {
            ft[ind]+=x;
            ind+=(ind&(-ind));
        }
    }
    int queryI(int ind) {
        ind+=1;
        int sum = 0;
        while (ind>0) {
            sum+=ft[ind];
            ind-=(ind&(-ind));
        }
        return sum;
    }
    int query(int a, int b) { return queryI(max(a,b))-queryI(min(a,b)-1); }
    int query(int a) { return queryI(a)-queryI(a-1); }
};

int n,q;
FT tree;

int main() {
    scanf("%d%d",&n,&q);
    int curLen = n;
    int start = 0;
    int flipped = 1;
    tree = FT(n);
    for (int i=0;i<n;i++) tree.update(i,1);
    for (int Q=0;Q<q;Q++) {
        int type;
        scanf("%d",&type);
        if (type==1) {
            int p;
            scanf("%d",&p);
            if (p<=curLen/2) {
                if (flipped==1) {
                    for (int i=0;i<p;i++) tree.update(start+p+i,tree.query(start+p-i-1));
                    start+=p;
                } else {
                    for (int i=0;i<p;i++) tree.update(start-p-i,tree.query(start-p+i+1));
                    start-=p;
                }
                curLen-=p;
            } else {
                if (flipped==1) {
                    for (int i=0;i<curLen-p;i++) tree.update(start+p-i-1,tree.query(start+p+i));
                    start+=p-1;
                } else {
                    for (int i=0;i<curLen-p;i++) tree.update(start-p+i+1,tree.query(start-p-i));
                    start-=p-1;
                }
                curLen-=curLen-p;
                flipped*=-1;
            }
        } else {
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%d\n",tree.query(start+l*flipped,start+(r-1)*flipped));
        }
    }

    return 0;
}