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
        vector <int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        while(!a.empty())
        {
            bool ok=false;
            for(int i=a.size()-1;i>=0;--i) if(a[i]%(i+2)!=0) {ok=true;a.erase(a.begin()+i);break;}
            if(!ok) break;
        }
        if(a.empty()) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}