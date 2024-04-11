#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200050;
int n,a[N];
int main(){
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    map<ll,int> was;
    was[0]=1;
    ll sum=0,ans=0;
    for(int i=1,pos=0;i<=n;i++){
        sum+=a[i];
        pos=max(pos,was[sum]);
        was[sum]=i+1;
        ans+=(i-pos);
    }
    printf("%lld",ans);
    return 0;
}