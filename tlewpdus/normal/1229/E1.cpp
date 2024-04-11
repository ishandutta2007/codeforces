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

int n;
ll arr[10][10];
int pcnt[200];
int loc[200];
vector<int> lis[10];
int nb[70][70];
ll i100;
ll D[7][(1<<20)+1];

ll ipow(ll a, ll n) {
    if (!n) return 1;
    ll t = ipow(a,n/2);
    return t*t%MOD*(n%2?a:1)%MOD;
}

int main() {
    i100 = ipow(100,MOD-2);
    scanf("%d",&n);
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            scanf("%lld",&arr[i][j]);
            arr[i][j] = arr[i][j]*i100%MOD;
        }
    }
    for (int i=1;i<(1<<n);i++) pcnt[i] = pcnt[i&(i-1)]+1;
    for (int i=0;i<(1<<n);i++) {
        loc[i] = lis[pcnt[i]].size();
        lis[pcnt[i]].push_back(i);
    }
    for (int i=0;i<(1<<n);i++) {
        for (int j=0;j<(1<<n);j++) {
            int res = 0;
            for (int k=j;k;k=((k-1)&j)) {
                if (pcnt[i|k]==pcnt[i]+1) {
                    res |= 1<<(loc[i|k]);
                }
            }
            nb[i][j] = res;
        }
    }
    D[0][1] = 1;
    for (int i=0;i<n;i++) {
        for (int bit=0;bit<(1<<n);bit++) {
            ll pro = 1;
            for (int j=0;j<n;j++) {
                if (bit>>j&1) pro = pro*arr[i][j]%MOD;
                else pro = pro*(MOD+1-arr[i][j])%MOD;
            }
            for (int pbit=0;pbit<(1<<lis[i].size());pbit++) {
                int res = 0;
                for (int j=0;j<lis[i].size();j++) {
                    if (pbit>>j&1) {
                        res |= nb[lis[i][j]][bit];
                    }
                }
                D[i+1][res]=(D[i+1][res]+D[i][pbit]*pro)%MOD;
            }
        }
    }
    printf("%lld\n",D[n][1]);

	return 0;
}