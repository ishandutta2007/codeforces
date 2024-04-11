#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const ll MOD = 998244353;
const ll half = (MOD+1)/2;

int n;
vector<int> lis[500100];
ll P[500100];

void dfs(int here, int p) {
    P[here] = 1;
    for (int &there : lis[here]){
        if (there==p) continue;
        dfs(there,here);
        P[here] = P[here]*half%MOD*(2-P[there])%MOD;
    }
}

int main() {
    int i;
    scanf("%d",&n);
    for (i=0;i<n-1;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back(b);
        lis[b].push_back(a);
    }
    dfs(0,-1);
    ll sum = 0;
    for (i=0;i<n;i++) sum += 1-P[i];
    for (i=0;i<n;i++) sum = sum*2%MOD;
    printf("%lld\n",(sum%MOD+MOD)%MOD);

    return 0;
}