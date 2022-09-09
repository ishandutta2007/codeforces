#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 998244353;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, m;
int arr[1000100], minl[510], maxl[510], tree[2100000];
const int key = 1048576;
vector<int> loc[510];
ll D[1010][1010];
int iskan[1010][1010];
int pmin[1010][1010];

void init() {
    for (int i=0;i<key*2;i++) tree[i] = INF;
}
void upd(int idx, int val) {
    idx+=key;
    while(idx) {
        tree[idx] = min(tree[idx],val);
        idx/=2;
    }
}
int getv(int s, int e) {
    s+=key; e+=key;
    int ans = INF;
    while(s<=e) {
        if (s&1)ans = min(ans,tree[s++]);
        if (~e&1) ans = min(ans,tree[e--]);
        s/=2; e/=2;
    }
    return ans;
}

ll calc(int s, int e) {
    if (s>e) return 1;
    if (~D[s][e]) return D[s][e];
    int tc = pmin[s][e];
    ll tv = 1;
    //printf("%d, %d : %d!\n",s,e,tc);
    for (int i=0;i+1<loc[tc].size();i++) {
        tv = tv*calc(loc[tc][i]+1,loc[tc][i+1]-1)%MOD;
    }
    //printf("%d, %d!!!\n",s,e);
    ll v = 0, w = 0;
    for (int i=loc[tc][0];i>=s;i--) {
        if (!iskan[tc][i-1]) continue;
        v += calc(i,loc[tc][0]-1)*calc(s,i-1)%MOD;
    }
    for (int i=loc[tc].back();i<=e;i++) {
        if (!iskan[tc][i]) continue;
        w += calc(loc[tc].back()+1,i)*calc(i+1,e)%MOD;
    }
    v%=MOD; w%=MOD;
    D[s][e] = v*w%MOD*tv%MOD;
    //printf("D  %d, %d : %lld (%lld, %lld)\n",s,e,D[s][e],v,w);
    return D[s][e];
}

void pung() {
    puts("0");
    exit(0);
}

int main() {
    scanf("%d%d",&n,&m);
    init();
    for (int i=1;i<=n;i++) {
        minl[i] = m+1;
        maxl[i] = 0;
    }
    for (int i=1;i<=m;i++) {
        scanf("%d",&arr[i]);
        if (arr[i]==arr[i-1]) {
            i--; m--;
        }
        /*ntf("%d, %d : ",i,m);
        for (int j=1;j<=i;j++) printf("%d ",arr[j]); printf("\n");
            */
    }
    for (int i=1;i<=m;i++) {
        minl[arr[i]] = min(minl[arr[i]],i);
        maxl[arr[i]] = max(maxl[arr[i]],i);
        loc[arr[i]].push_back(i);
        upd(i,arr[i]);
    }
    for (int i=1;i<=n;i++) {
        if (getv(minl[i],maxl[i])<i) {
            pung();
        }
    }
    for (int i=1;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            int fl = 0;
            for (int k=i;k<=n;k++) {
                if (maxl[k]<=j||j<minl[k]) continue;
                fl = 1; break;
            }
            if (!fl) iskan[i][j] = 1;
            //printf("%d, %d : %d\n",i,j,iskan[i][j]);
        }
    }
    for (int i=1;i<=m;i++) {
        for (int j=i;j<=m;j++) {
            pmin[i][j] = getv(i,j);
        }
    }
    memset(D,-1,sizeof(D));
    printf("%lld\n",calc(1,m));

    return 0;
}