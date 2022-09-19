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
        int n;
        cin>>n;
        string s[n];
        for(int i=0;i<n;++i) cin>>s[i];
        bool ok=false;
        for(int i=0;i<n;++i)
        {
            string t=s[i];reverse(t.begin(),t.end());
            if(s[i]==t) ok=true;
        }
        set <string> o;
        for(int i=n-1;i>=0;--i)
        {
             string t=s[i];
             reverse(t.begin(),t.end());
             if(o.count(t)) ok=true;
             string t1=s[i];
             t1.pop_back();
             reverse(t1.begin(),t1.end());
             if(o.count(t1)) ok=true;
             o.insert(s[i]);
        }
        set <string> o2;
        for(int i=0;i<n;++i)
        {
             string t=s[i];
             t.erase(t.begin());
             reverse(t.begin(),t.end());
             if(o2.count(t)) ok=true;
             o2.insert(s[i]);
        }
        if(ok) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}