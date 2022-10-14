#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;scanf("%i%i",&n,&k);
    multiset<long long> s;
    for(int i=0;i<k+1;i++)s.insert(0);
    long long a[n];
    for(int i=0;i<n;i++)scanf("%lld",&a[i]);
    sort(a,a+n);reverse(a,a+n);
    long long ans=0;
    for(int i=0;i<n;i++){
        auto it=s.end();
        --it;
        ans+=*it;
        long long r=*it+a[i];
        s.erase(it);
        s.insert(r);
    }
    //for(long long c:s)ans+=c;
    printf("%lld",ans);
    return 0;
}