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
    string s;
    cin>>s;
    int u=0;
    for(int i=0;i<=(n-7);++i)
    {
        if(s.substr(i,7)=="abacaba")
        {
            ++u;
        }
    }
    if(u==1)
    {
        cout<<"Yes"<<endl;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='?') s[i]='z';
        }
        cout<<s<<endl;
        continue;
    }
    else if(u>=2)
    {
        cout<<"No"<<endl;
        continue;
    }
    else
    {
        string h="abacaba";
        bool z=false;
        int r=0;
        for(int i=0;i<=(n-7);++i)
        {
            string s1=s;
            bool u=true;
            for(int j=0;j<7;++j)
            {
                if(s[i+j]==h[j] || s[i+j]=='?')
                {

                }
                else
                {
                    u=false;
                }
            }
            if(u)
            {
                for(int j=0;j<7;++j)
                {
                    if(s[i+j]=='?')
                    {
                        s[i+j]=h[j];
                    }
                }
                for(int j=0;j<n;++j)
                {
                    if(s[j]=='?')
                    {
                        s[j]='z';
                    }
                }
                int u=0;
                for(int j=0;j<=(n-7);++j)
                {
                    if(s.substr(j,7)==h)
                    {
                        ++u;
                    }
                }
                if(u==1)
                {
                cout<<"Yes"<<endl;
                cout<<s<<endl;
                z=true;
                break;
                }
            }
            s=s1;
        }
        if(!z)
        {
            cout<<"No"<<endl;
            continue;
        }
    }
    }
    return 0;
}