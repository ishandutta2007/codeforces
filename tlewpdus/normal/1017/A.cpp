#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;

int main() {
    int i;

    scanf("%d",&n);
    int tsum = 0, cnt = 1;
    for (i=0;i<n;i++) {
        int a, sum = 0;
        for (int j=0;j<4;j++) {
            scanf("%d",&a);
            sum += a;
        }
        if (i==0) {
            tsum = sum;
        }
        else {
            if (sum>tsum) cnt++;
        }
    }
    printf("%d\n",cnt);

    return 0;
}