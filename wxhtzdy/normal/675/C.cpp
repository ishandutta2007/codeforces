#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=100050;
int a[N];
int main(){
    int n;scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    map<ll,int> cnt;
    ll sum=0,ans=n-1;
    for(int i=1;i<=n;i++){
        sum+=a[i];
        cnt[sum]++;
        ans=min(ans,(ll)n-cnt[sum]);
    }
    printf("%i",ans);
    return 0;
}