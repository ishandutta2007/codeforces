#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

int main() {
    int n;

    scanf("%d",&n);
    int i, maxi = -987654321;
    for (i=0;i<n;i++) {
        int a, b = 0;
        scanf("%d",&a);
        for (int j=0;j<=1010;j++) if (j*j==a) b = 1;
        if (!b) maxi = max(maxi,a);
    }
    printf("%d\n",maxi);

    return 0;
}