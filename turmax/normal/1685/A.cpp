#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];sort(a,a+n);
        if(n%2==1) {cout<<"NO"<<'\n';continue;}
        int b[n];for(int i=0;i<n;++i) {b[(2*i)%n+(2*i)/n]=a[i];}
        bool ok=true;
        for(int i=0;i<n;++i) {bool ok1=false;if(b[i]>b[(i+n-1)%n] && b[i]>b[(i+1)%n]) {ok1=true;} if(b[i]<b[(i+n-1)%n] && b[i]<b[(i+1)%n]) {ok1=true;} ok&=(ok1);}
        if(!ok) {cout<<"NO"<<'\n';continue;}
        cout<<"YES"<<'\n';for(int i=0;i<n;++i) cout<<b[i]<<' '; cout<<'\n';
    }
    return 0;
}