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

ll a, b, c;

int main() {
    scanf("%lld%lld%lld",&a,&b,&c);
    printf("%lld\n",2*c+min(a,b)*2+(a==b?0:1));

    return 0;
}