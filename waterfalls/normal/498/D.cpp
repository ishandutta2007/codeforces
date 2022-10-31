#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,q;
int A[100013];
int st[60][400013];

int left(int w) { return w<<1; }
int right(int w) { return (w<<1)+1; }
void buildI(int w, int L, int R) {
    for (int id=0;id<60;id++) st[id][w] = R-L+1;
    if (L!=R) {
        buildI(left(w),L,(L+R)/2);
        buildI(right(w),(L+R)/2+1,R);
    }
}
void build() { buildI(1,0,n-1); }
int queryI(int id, int w, int L, int R, int a, int b) {
    if (a>R || b<L) return 0;
    if (a<=L && b>=R) return st[id][w];
    int one = queryI(id,left(w),L,(L+R)/2,a,b);
    int two = queryI((id+one)%60,right(w),(L+R)/2+1,R,a,b);
    return one+two;
}
int query(int id, int a, int b) { return queryI(id,1,0,n-1,a,b); }
void updateAllI(int w, int L, int R, int a, int val) {
    if (a>R || a<L) return;
    if (L==R) {
        for (int id=0;id<60;id++) {
            if ((A[a]!=0 && id%A[a]==0) && id%val!=0) st[id][w]-=1;
            if ((A[a]==0 || id%A[a]!=0) && id%val==0) st[id][w]+=1;
        }
        return;
    }
    if (a<=(L+R)/2) {
        updateAllI(left(w),L,(L+R)/2,a,val);
        for (int id=0;id<60;id++) st[id][w] = st[id][left(w)]+st[(id+st[id][left(w)])%60][right(w)];
    } else {
        updateAllI(right(w),(L+R)/2+1,R,a,val);
        for (int id=0;id<60;id++) st[id][w] = st[id][left(w)]+st[(id+st[id][left(w)])%60][right(w)];
    }
}
void updateAll(int a, int val) { updateAllI(1,0,n-1,a,val); }

int main() {
    scanf("%d",&n);
    build();
    for (int i=0;i<n;i++) {
        int time;
        scanf("%d",&time);
        updateAll(i,time);
        A[i] = time;
    }
    scanf("%d",&q);
    for (int Q=0;Q<q;Q++) {
        char type;
        int x,y;
        scanf(" %c%d%d",&type,&x,&y);
        if (type=='A') printf("%d\n",query(0,x-1,y-2));
        else {
            updateAll(x-1,y);
            A[x-1] = y;
        }
    }

    return 0;
}