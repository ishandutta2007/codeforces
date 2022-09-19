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
        string s;
        cin>>s;
        map <char,int> u;
        vector <int> v={-1,1};
        bool h=false;
        for(auto z1:v)
        {
            for(auto z2:v)
            {
                for(auto z3:v)
                {
                    u['A']=z1;u['B']=z2;u['C']=z3;
                    int sh=0,mi=0;
                    for(int i=0;i<s.size();++i)
                    {
                        sh+=u[s[i]];
                        mi=min(mi,sh);
                    }
                    if(mi==0 && sh==0)
                    {
                        h=true;
                    }
                }
            }
        }
        if(h) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}