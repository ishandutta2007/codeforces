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
int arr[300100];

int main() {
    int i;

    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    if (arr[0]!=arr[n-1]) {
        printf("%d\n",n-1);
    }
    else {
        int res = 0;
        for (i=0;i<n;i++) if (arr[i]!=arr[n-1]) break;
        res = n-1-i;
        for (i=n-1;i>=0;i--) if (arr[0]!=arr[i]) break;
        res=  max(res,i);
        printf("%d\n",res);
    }

    return 0;
}