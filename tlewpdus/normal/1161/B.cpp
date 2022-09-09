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

int n, m;
vector<int> lis[100100];

bool chk(int k) {
    int i, j;
    for (i=0;i<n;i++) {
        j = (i+k)%n;
        if (lis[i].size()!=lis[j].size()) return false;
        for (int l=0;l<lis[i].size();l++) if (lis[i][l]!=lis[j][l]) return false;
    }
    return true;
}

int main() {
    int i;

    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back((b-a+n)%n);
        lis[b].push_back((a-b+n)%n);
    }
    for (i=0;i<n;i++) sort(lis[i].begin(),lis[i].end());
    for (i=1;i<n;i++) {
        if (n%i) continue;
        if (chk(i)) {
            puts("Yes");
            return 0;
        }
    }
    puts("No");

    return 0;
}