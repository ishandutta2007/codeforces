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

int b, k;

int main() {
    int i;

    scanf("%d%d",&b,&k);
    int s = 0;
    for (i=0;i<k;i++) {
        int a;
        scanf("%d",&a);
        if (b%2) s += a%2;
        else if (i==k-1) s+=a%2;
    }
    puts(s%2?"odd":"even");

    return 0;
}