#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m;
vector<ll> lis[3010];
int key[3010];

int main() {
    int i, j, k;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        int p; ll c;
        scanf("%d%lld",&p,&c); p--;
        lis[p].push_back(c);
    }
    for (i=1;i<m;i++) sort(lis[i].begin(),lis[i].end());
    for (i=1;i<m;i++) {
        key[i] = 0;
    }

    ll mini = 1e18;
    for (i=max((int)lis[0].size(),1);i<=n;i++) {
        int v = i-(int)lis[0].size(), cnt = 0;
        ll sum = 0;
        vector<ll> trr;
        for (j=1;j<m;j++) {
            cnt += max((int)lis[j].size()-i+1,0);
            for (k=0;k<max((int)lis[j].size()-i+1,0);k++) {
                sum += lis[j][k];
            }
            for (;k<lis[j].size();k++) trr.push_back(lis[j][k]);
        }
        if (cnt<v) {
            sort(trr.begin(),trr.end());
            for (j=0;j<v-cnt;j++) sum += trr[j];
        }
        mini = min(mini,sum);
    }
    printf("%lld\n",mini);

    return 0;
}