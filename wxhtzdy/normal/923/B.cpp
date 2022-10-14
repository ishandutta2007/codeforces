#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n;scanf("%i",&n);
    ll a[n],b[n];
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    for(int i=0;i<n;i++)scanf("%lld",&b[i]);
    ll sum=0;
    multiset<ll> s;
    for(int i=0;i<n;i++){
        s.insert(a[i]+sum);
        ll ans=0;
        while(s.size()>0&&(*s.begin()-sum)<=b[i]){
            ans+=(*s.begin()-sum);
            s.erase(s.begin());
        }
        printf("%lld ",ans+(ll)s.size()*b[i]);
        sum+=b[i];
    }
    return 0;
}