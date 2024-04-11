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

ll n;

int main() {
    vector<ll> vec;
    scanf("%lld",&n);
    if (n==1) {
        puts("1");
        return 0;
    }
    for (ll i=2;i*i<=n;i++) {
        if (n%i==0) {
            vec.push_back(i);
            while(n%i==0) {
                n/=i;
            }
            if (n!=1) {
                puts("1");
                return 0;
            }
        }
    }
    if (n>1) {
        vec.push_back(n);
    }
    printf("%lld\n",vec[0]);

	return 0;
}