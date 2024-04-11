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

int n, k;

int main() {
    int i;

    scanf("%d%d",&n,&k);
    int r = (n-k)/2+1;
    for (i=0;i<n;i++) {
        if (i%r==r-1) printf("1");
        else printf("0");
    }
    printf("\n");

    return 0;
}