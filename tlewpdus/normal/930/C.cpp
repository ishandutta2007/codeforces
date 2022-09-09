#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n, m;
int psum[100100];
int lis[100100];
int lds[100100];

int bit[100100];
void init() {
    int i;
    for (i=0;i<=n+1;i++) bit[i] = 0;
}

void upd(int idx, int val) {
    idx++;
    while(idx<=n+1) {
        bit[idx] = max(bit[idx],val);
        idx += idx&-idx;
    }
}

int getv(int idx) {
    int res = 0;
    idx++;
    while(idx) {
        res = max(res,bit[idx]);
        idx-=idx&-idx;
    }
    return res;
}

int main() {
    int i;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        int a, b;
        scanf("%d%d",&a,&b); a--; b--;
        psum[a]++; psum[b+1]--;
    }
    for (i=1;i<m;i++) psum[i] += psum[i-1];
    init();
    for (i=0;i<m;i++) {
        lis[i] = getv(psum[i])+1;
        upd(psum[i],lis[i]);
    }
    init();
    for (i=m-1;i>=0;i--) {
        lds[i] = getv(psum[i])+1;
        upd(psum[i],lds[i]);
    }
    int res = 0;
    for (i=0;i<m;i++) {
        res = max(res,lis[i]+lds[i]-1);
    }
    printf("%d\n",res);

    return 0;
}