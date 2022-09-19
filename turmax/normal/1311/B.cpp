#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        int n,m;
        cin>>n>>m;
        vector <int> a(n);
        vector <int> b(m);
        vector <bool> is(n);
        for(int i=0;i<n;++i)
        {
            is[i]=false;
            cin>>a[i];
        }
        for(int i=0;i<m;++i)
        {
            cin>>b[i];
            b[i]--;
            is[b[i]]=true;
        }
        int l=0;
        for(int i=0;i<(n-1);++i)
        {
            if(!is[i])
            {
                sort(a.begin()+l,a.begin()+i+1);
                l=(i+1);
            }
        }
        sort(a.begin()+l,a.begin()+n);
        bool h=false;
        for(int i=0;i<(n-1);++i)
        {
            if(a[i]>a[i+1])
            {
                cout<<"NO"<<endl;
                h=true;
                break;
            }
        }
        if(!h)
        {
            cout<<"YES"<<endl;
        }
    }
    return 0;
}