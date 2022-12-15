#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back

ll n, l, r, a, b, i;

int main(){
    scanf("%lld%lld%lld",&n,&l,&r); l--;
    for(i=1;i<=n-l;i++) a++;
    for(i=1;i<=l;i++) a+=(1<<i);
    for(i=1;i<=r;i++) b+=(1<<(i-1));
    for(i=1;i<=n-r;i++) b+=(1<<(r-1));
    printf("%lld %lld\n",a,b);
    return 0;
}