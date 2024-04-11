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

int n, c;
vector<int> loc[500100];
int arr[500100];
int csum[500100];

int main() {
    int i, t = 0;

    scanf("%d%d",&n,&c);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        if (arr[i]==c) {
            csum[i] = 1;
            t++;
        }
        else loc[arr[i]].push_back(i);
    }
    for (i=1;i<n;i++) csum[i]+=csum[i-1];
    int j;
    int ans = t;
    for (i=1;i<=500001;i++) {
        if (loc[i].empty()) continue;
        vector<int> vec;
        for (j=0;j<loc[i].size();j++) vec.push_back(csum[loc[i][j]]);
        int mini = 1e9;
        for (j=0;j<vec.size();j++) {
            mini = min(mini,j-vec[j]);
            ans = max(ans,t+j-vec[j]-mini+1);
        }
    }
    printf("%d\n",ans);

    return 0;
}