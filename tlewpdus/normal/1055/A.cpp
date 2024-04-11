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

int n, s;
int arr[1010], brr[1010];

int main() {
    int i;

    scanf("%d%d",&n,&s); s--;
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    for (i=0;i<n;i++) scanf("%d",&brr[i]);
    bool fl = 0;
    if (arr[0]&&arr[s]) fl = 1;
    else {
        for (i=s;i<n;i++) {
            if (arr[0]&&arr[i]&&brr[i]&&brr[s]) fl = 1;
        }
    }
    if (fl) printf("YES\n");
    else printf("NO\n");

    return 0;
}