#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    for(int cyc=0;cyc<t;++cyc)
    {
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        int n=s1.size();
        bool h=true;
        for(int i=0;i<n;++i)
        {
            if(s1[i]!=s3[i] && s2[i]!=s3[i])
            {
                h=false;
            }
        }
        if(h)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}