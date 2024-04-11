#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int k;
int nxt[100100];
vector<ll> arr[20];
vector<ll> ord[20];
int idx[100100];
int D[50100];
int via[50100];
int chk[50100];
int ji[100100];
pll dab[20];
map<ll,pii> mip;
ll sum;

void pung() {
    puts("No");
    exit(0);
}

vector<int> ans;
void dfs(int bit) {
    if (via[bit]==bit) {
        ans.push_back(bit);
        return;
    }
    dfs(via[bit]);
    dfs(bit^via[bit]);
}

int main() {
    int p = 0;
    scanf("%d",&k);
    for (int i=0;i<k;i++) {
        int ni;
        scanf("%d",&ni);
        for (int j=0;j<ni;j++) {
            int a;
            scanf("%d",&a);
            arr[i].push_back(a);
            ord[i].push_back(p++);
            idx[p-1] = i;
            ji[p-1] = j;
            mip[a]=pii(i,j);
            sum+=a;
        }
    }
    if (sum%k!=0) {
        pung();
    }
    for (int i=0;i<k;i++) {
        ll tsum = 0;
        for (int j=0;j<arr[i].size();j++) {
            tsum += arr[i][j];
        }
        for (int j=0;j<arr[i].size();j++) {
            ll v = sum/k-tsum+arr[i][j];
            if (mip.find(v)!=mip.end()&&
                (mip[v].first!=i||(mip[v].first==i&&mip[v].second==j))) nxt[ord[i][j]] = ord[mip[v].first][mip[v].second];
            else nxt[ord[i][j]] = -1;
        }
    }
    for (int i=0;i<k;i++) {
        for (int j=0;j<arr[i].size();j++) {
            int bit = 1<<i;
            int p = ord[i][j];
            while(1) {
                p=nxt[p];
                if (idx[p]==i) {
                    if (ji[p]!=j) {
                        break;
                    }
                    D[bit] = 1;
                    chk[bit] = ord[i][j];
                    break;
                }
                if (p==-1||(bit>>idx[p]&1)) break;
                bit |= 1<<idx[p];
            }
        }
    }
    D[0] = 1;
    for (int i=0;i<(1<<k);i++) {
        for (int j=i;j;j=((j-1)&i)) {
            if (D[j]&&D[i^j]) {
                D[i] = 1;
                via[i] = j;
                break;
            }
        }
    }
    if (!D[(1<<k)-1]) pung();
    dfs((1<<k)-1);
    for (int &bit : ans) {
        int p = chk[bit];
        int i = idx[p];
        while(1) {
            dab[idx[p]].first = arr[idx[p]][ji[p]];
            dab[idx[nxt[p]]].second = idx[p];
            p=nxt[p];
            if (idx[p]==i) {
                break;
            }
        }
    }
    puts("Yes");
    for (int i=0;i<k;i++) {
        printf("%lld %lld\n",dab[i].first,dab[i].second+1);
    }

	return 0;
}