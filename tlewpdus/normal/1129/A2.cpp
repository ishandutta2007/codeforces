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
vector<int> lis[5010];
int arr[5010];

int dis(int a, int b) {
    return (a<=b)?(b-a):(b-a+n);
}
int main() {
    int i;

    scanf("%d%d",&n,&m);
    for (i=0;i<m;i++) {
        int a, b;
        scanf("%d%d",&a,&b); --a; --b;
        lis[a].push_back(b);
    }
    for (i=0;i<n;i++) {
        if (lis[i].empty()) {
            arr[i] = -1e8;
            continue;
        }
        sort(lis[i].begin(),lis[i].end(),[&](int a, int b){return dis(i,a)>dis(i,b);});
        arr[i] = n*((int)lis[i].size()-1)+dis(i,lis[i].back());
    }
    for (i=0;i<n;i++) {
        int ans = 0;
        for (int j=0;j<n;j++) ans = max(ans,arr[j]+dis(i,j));
        printf("%d ",ans);
    }
    printf("\n");

    return 0;
}