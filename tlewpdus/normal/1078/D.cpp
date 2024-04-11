#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int key = 524288;
struct idxtree {
    int tree[1050000];
    void init() {
        int i;
        for (i=0;i<key*2;i++) tree[i] = -INF;
    }
    void upd(int idx, int val) {
        idx += key;
        while(idx) {
            tree[idx] = max(tree[idx],val);
            idx/=2;
        }
    }
    int getv(int s, int e) {
        s += key; e += key;
        int v = -INF;
        while(s<=e) {
            if (s&1) v = max(v,tree[s]);
            if (~e&1) v = max(v,tree[e]);
            s = (s+1)/2;
            e = (e-1)/2;
        }
        return v;
    }
    int f(int x, int tt) {
        while(x<key) {
            if (tt<0) {
                if (tree[x]==tree[x*2]) x = x*2;
                else x = x*2+1;
            }
            else {
                if (tree[x]==tree[x*2+1]) x = x*2+1;
                else x = x*2;
            }
        }
        return x-key;
    }
    int geti(int s, int e, int tt) {
        int t = getv(s,e);
        s += key; e += key;
        while(s<=e) {
            if (s&1) {
                if (tree[s]==t) return f(s,tt);
            }
            if (~e&1) {
                if (tree[e]==t) return f(e,tt);
            }
            s = (s+1)/2;
            e = (e-1)/2;
        }
        return -1;
    }
} mt, Mt;

int n;
int arr[300100];
int le[300100][20], re[300100][20];
int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    for (i=n;i<3*n;i++) arr[i] = arr[i-n];
    mt.init(); Mt.init();
    for (i=0;i<3*n;i++) {
        Mt.upd(i,i+arr[i]);
        mt.upd(i,arr[i]-i);
    }
    for (i=n;i<2*n;i++) {
        le[i][0] = i-arr[i];
        re[i][0] = i+arr[i];
    }
    for (i=0;i<n;i++) {le[i][0] = max(le[i+n][0]-n,0); re[i][0] = max(re[i+n][0]-n,0);}
    for (i=2*n;i<3*n;i++) {le[i][0] = min(le[i-n][0]+n,3*n-1); re[i][0] = min(re[i-n][0]+n,3*n-1);}
    int j;
    for (j=1;j<20;j++) {
        for (i=0;i<3*n;i++) {
            int lt = mt.geti(le[i][j-1],re[i][j-1],1), rt = Mt.geti(le[i][j-1],re[i][j-1],-1);
            le[i][j] = min(le[lt][j-1],le[rt][j-1]);
            re[i][j] = max(re[lt][j-1],re[rt][j-1]);
        }
    }
    for (i=n;i<2*n;i++) {
        int l = i, r = i, v = 0;
        for (j=19;j>=0;j--) {
            int lt = mt.geti(l,r,1), rt = Mt.geti(l,r,-1);
            if (max(re[rt][j],re[lt][j])-min(le[rt][j],le[lt][j])<n-1) {
                l = min(le[rt][j],le[lt][j]);
                r = max(re[rt][j],re[lt][j]);
                v += 1<<j;
            }
        }
        if (n!=1) v++;
        printf("%d ",v);
    }
    printf("\n");

    return 0;
}