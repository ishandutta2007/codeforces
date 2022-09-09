#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;
int mini = 1e9;

int main() {
    int i;

    scanf("%d",&n);
    int t = 1;
    for (i=1;i<=n;i++) {
        if (mini>i+(n+i-1)/i) {
            mini=i+(n+i-1)/i;
            t=i;
        }
    }
    for (i=1;(i-1)*t<n;i++) {
        for (int j=min(i*t,n);j>(i-1)*t;j--) {
            printf("%d ",j);
        }
    }
    printf("\n");

    return 0;
}