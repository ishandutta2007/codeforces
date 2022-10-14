#include <bits/stdc++.h>
using namespace std;

const int N=200050;
int a[N];

void solve(){
    int n,p,k;scanf("%i%i%i",&n,&p,&k);
    for(int i=1;i<=n;i++)scanf("%i",&a[i]);
    sort(a+1,a+n+1);
    long long pref[n+1];
    for(int i=1;i<=n;i++){
        pref[i]=a[i]+(i>k?pref[i-k]:0LL);
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(pref[i]<=p)ans=i;
    printf("%i\n",ans);
}

int main(){
    int t;scanf("%i",&t);
    while(t--)
        solve();
    return 0;
}