#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int n,q,a[N];
ll pref[N];
set<ll> all;
void Solve(int l,int r){
    int mid=(a[l]+a[r])/2;
    ll sum=pref[r]-pref[l-1];
    all.insert(sum);
    //printf("%i %i %i %i %i\n",l,r,a[l],a[r],sum);
    int j=l;
    for(int i=l;i<=r;i++){
        if(a[i]<=mid)j=i;
    }
    if(j!=r){
        Solve(l,j);
        Solve(j+1,r);
    }
}
int main(){
    int t;scanf("%i",&t);
    while(t--){
        scanf("%i %i",&n,&q);
        all.clear();
        for(int i=1;i<=n;i++)scanf("%i",&a[i]);
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)pref[i]=pref[i-1]+a[i];
        Solve(1,n);
        while(q--){
            ll x;scanf("%lld",&x);
            if(all.find(x)!=all.end())printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}