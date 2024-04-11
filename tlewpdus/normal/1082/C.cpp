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

int n, m;
vector<int> vec[100100];
int ord[100100];

int main() {
    int i, j;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        int s, r;
        scanf("%d%d",&s,&r);
        vec[s-1].push_back(r);
    }
    for (i=0;i<m;i++) sort(vec[i].begin(),vec[i].end(),greater<int>());
    for (i=0;i<m;i++) for (j=1;j<vec[i].size();j++) vec[i][j]+=vec[i][j-1];
    for (i=0;i<m;i++) ord[i] = i;
    sort(ord,ord+m,[](int a, int b){return vec[a].size()>vec[b].size();});
    int ans = 0;
    for (i=0;i<n;i++) {
        int v = 0;
        for (j=0;j<m&&vec[ord[j]].size()>i;j++) {
            v += max(vec[ord[j]][i],0);
        }
        ans = max(ans,v);
    }
    printf("%d\n",ans);

    return 0;
}