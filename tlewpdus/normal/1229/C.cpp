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

int n, m, q;
vector<int>lis[100100];
ll ans;
ll id[100100];

void Do(int v) {
    ans -= id[v]*lis[v].size();
    for (int &w : lis[v]) {
        ans -= id[w]*lis[w].size();
        id[w]--;
        lis[w].push_back(v);
        ans += id[w]*lis[w].size();
    }
    id[v] += lis[v].size();
    lis[v].clear();
}

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b);
        a--; b--;
        if (a>b) swap(a,b);
        lis[a].push_back(b);
        id[b]++;
    }
    for (int i=0;i<n;i++) ans += id[i]*lis[i].size();
    printf("%lld\n",ans);
    scanf("%d",&q);
    for (int i=0;i<q;i++) {
        int a;
        scanf("%d",&a); a--;
        Do(a);
        printf("%lld\n",ans);
    }

	return 0;
}