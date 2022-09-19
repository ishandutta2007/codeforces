#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        int g=0;
        set <int> l;
        int o;
        for(int i=0;i<n;++i) {cin>>a[i];o=a[0];l.insert(a[i]);if(a[i]!=o) g=__gcd(g,a[i]-o);}
        if(a[0]==k) {cout<<"YES"<<endl;continue;}
        if(g==0 || ((k-a[0])%g)!=0 || l.size()==1) {cout<<"NO"<<endl;continue;}
        {cout<<"YES"<<endl;continue;}
    }
    return 0;
}