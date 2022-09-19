#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        int a,b,c;
        cin>>a>>b>>c;
        int s=0;
        if(a!=0)
        {
            a--;
            ++s;
        }
        if(b!=0)
        {
            b--;
            ++s;
        }
        if(c!=0)
        {
            c--;
            ++s;
        }
        vector <int> v;
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        if(v[0]>=1 && v[1]>=1)
        {
            v[0]--;
            v[1]--;
            ++s;
        }
        if(v[0]>=1 && v[2]>=1)
        {
            v[0]--;
            v[2]--;
            ++s;
        }
        if(v[2]>=1 && v[1]>=1)
        {
            v[2]--;
            v[1]--;
            ++s;
        }
        if(v[1] && v[2] && v[0])
        {
            ++s;
        }
        cout<<s<<endl;
    }
    return 0;
}