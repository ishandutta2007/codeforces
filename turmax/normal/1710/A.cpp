#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n,m,k;cin>>n>>m>>k;int a[k];for(int i=0;i<k;++i) cin>>a[i];
        int sum=0;for(int i=0;i<k;++i) {if(a[i]>=n*m) ++sum;} if(sum>=1) {puts("Yes");continue;}
        int sum1=0;int sum11=0;bool ok=false;for(int i=0;i<k;++i) {if(a[i]>=2*n) {sum1+=(a[i]/n);if(a[i]>=3*n) ok=true;sum11+=2;}} if(sum1>=m && (ok || m%2==0)) {puts("Yes");continue;}
        int sum2=0;ok=false;for(int i=0;i<k;++i) {if(a[i]>=2*m) {sum2+=(a[i]/m);if(a[i]>=3*m) ok=true;}} if(sum2>=n && (ok || n%2==0)) {puts("Yes");continue;}
        puts("No");
    }
    return 0;
}