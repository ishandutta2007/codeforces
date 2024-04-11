#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin>>q;
    string s1,s2;
    int u;
    int d;
    for(int i=0;i<q;++i)
    {
        d=0;
        u=0;
        cin>>s1>>s2;
        for(int j=0;j<s1.size();++j)
        {
            for(int k=0;k<s1.size();++k)
            {
                if(s1[j]==s2[k])
                {
                    if(d==0)
                    {
                        cout<<"YES"<<endl;
                    }
                    d=1;
                }
            }
        }
        if(d==0)
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}