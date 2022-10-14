#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int n;
ll k,a[N];
int main(){
    int t;scanf("%i",&t);
    while(t--){
        scanf("%lld%lld",&n,&k);
        for(int i=0;i<n;i++)scanf("%lld",&a[i]);
        sort(a,a+n);
        ll g=a[1]-a[0];
        for(int i=2;i<n;i++)g=__gcd(g,a[i]-a[i-1]);
        if((a[0]-k)%g==0)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}