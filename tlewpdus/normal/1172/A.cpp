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
int arr[200100], brr[200100];
int aloc[200100], bloc[200100];

int main() {
    int i;

    scanf("%d",&n);
    fill(aloc,aloc+n+1,-1);
    fill(bloc,bloc+n+1,-1);
    for (i=0;i<n;i++) {
        scanf("%d",&arr[i]);
        aloc[arr[i]] = i;
    }
    for (i=0;i<n;i++) {
        scanf("%d",&brr[i]);
        bloc[brr[i]] = i;
    }
    if (bloc[1]>=0) {
        bool bad = 0;
        for (i=bloc[1];i<n;i++) {
            if (brr[i]!=i-bloc[1]+1) bad = 1;
        }
        if (!bad) {
            for (i=brr[n-1]+1;i<=n;i++) {
                if (bloc[i]>=0&&bloc[i]>=i-brr[n-1]-1) bad = 1;
            }
            if (!bad) {
                printf("%d\n",bloc[1]);
                return 0;
            }
        }
    }
    int maxi = -2;
    for (i=0;i<n;i++) {
        if (brr[i]) maxi = max(maxi,i-brr[i]);
    }
    printf("%d\n",maxi+n+2);

    return 0;
}