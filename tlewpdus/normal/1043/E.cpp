#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n, m;
vector<int> lis[300100];
ll x[300100], y[300100];
ll ans[300100];
ll px[300100], py[300100];
int ord[300100];

ll cal(int i, int j) {
    return min(x[i]+y[j],x[j]+y[i]);
}

int main() {
    int i;

    scanf("%d%d",&n,&m);
    for (i=0;i<n;i++) {
        scanf("%lld%lld",&x[i],&y[i]);
    }
    for (i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        ans[a]-=cal(a,b);
        ans[b]-=cal(a,b);
    }
    for (i=0;i<n;i++) ord[i] = i;
    sort(ord,ord+n,[](int a, int b){return x[a]-y[a]<x[b]-y[b];});
    px[0] = x[ord[0]];
    py[0] = y[ord[0]];
    for (i=1;i<n;i++) {
        px[i] = px[i-1]+x[ord[i]];
        py[i] = py[i-1]+y[ord[i]];
    }
    for (i=0;i<n;i++) {
        ans[ord[i]] += i*y[ord[i]]+(n-1-i)*x[ord[i]]+(i?px[i-1]:0)+py[n-1]-py[i];
    }
    for (i=0;i<n;i++) printf("%lld ",ans[i]);
    printf("\n");

    return 0;
}