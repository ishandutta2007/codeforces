#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    vector <int> a(n);
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    int ans=0;
    vector <int> res;
    for(int j=0;j<n;++j)
    {
        int s=0;
        vector <int> v(n);
        v[j]=a[j];
        s+=v[j];
        int mi1=a[j];
        int mi2=a[j];
        for(int i=(j-1);i>=0;--i)
        {
            mi1=min(mi1,a[i]);
            v[i]=mi1;
            s+=v[i];
        }
        for(int i=(j+1);i<n;++i)
        {
            mi2=min(mi2,a[i]);
            v[i]=mi2;
            s+=v[i];
        }
        if(s>ans)
        {
            ans=s;
            res=v;
        }
    }
    //cout<<ans<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<res[i]<<" ";
    }
    return 0;
}