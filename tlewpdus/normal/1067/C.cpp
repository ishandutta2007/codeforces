#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;

int main() {
    scanf("%d",&n);
    int i;
    if (n<=12) {
        for (i=0;i<n/2;i++) printf("0 %d\n",i);
        for (i=0;i<n-n/2;i++) printf("1 %d\n",i);
    }
    else {
        for (i=0;i<2*n/3;i++) printf("0 %d\n",i);
        for (i=0;i<n-2*n/3;i++) printf("3 %d\n",i*2+1);
    }

    return 0;
}