#pragma GCC optimize("O3","Ofast","unroll-loops")
#pragma GCC target("avx2")
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
        vector <int> v1,v2;
        for(int i=0;i<n;++i) {cin>>a[i];if(i%2==0) v1.push_back(a[i]); else v2.push_back(a[i]);}
        bool ans=true;
        for(auto h:v1)
        {
            if(h%2==0)
            {
                ans=false;
            }
        }
        if(!ans) {cout<<(-1)<<endl;continue;}
        vector <int> res;
        for(int i=0;i<n/2;++i)
        {
            int pos1,pos2;
            for(int j=0;j<n;++j)
            {
                if(a[j]==(2*i+1)) pos1=j;
                else if(a[j]==(2*i+2)) pos2=j;
            }
            res.push_back(pos1+1);
            reverse(a.begin(),a.begin()+pos1+1);
            for(int j=0;j<n;++j)
            {
                if(a[j]==(2*i+1)) pos1=j;
                else if(a[j]==(2*i+2)) pos2=j;
            }
            assert(pos1==0);
            res.push_back(pos2);
            reverse(a.begin(),a.begin()+pos2);
            for(int j=0;j<n;++j)
            {
                if(a[j]==(2*i+1)) pos1=j;
                else if(a[j]==(2*i+2)) pos2=j;
            }
            assert(pos1==(pos2-1));
            res.push_back(pos2+2);
            reverse(a.begin(),a.begin()+pos2+2);
            res.push_back(3);
            reverse(a.begin(),a.begin()+3);
            res.push_back(n-2*i);
            reverse(a.begin(),a.begin()+n-(2*i));
        }
        res.push_back(n);
        reverse(a.begin(),a.begin()+n);
        cout<<res.size()<<endl;
        for(auto h:res) cout<<h<<' ';
        cout<<endl;
    }
    return 0;
}