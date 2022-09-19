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
        int a[n][n];
        for(int i=0;i<n;++i) for(int j=0;j<n;++j) a[i][j]=0;
        for(int i=0;i<n;++i)
        {
            string s;
            cin>>s;
            for(int j=0;j<n;++j)
            {
                if(s[j]=='1')
                {
                    a[i][j]^=1;
                }
            }
        }
        for(int i=0;i<n;++i)
        {
            string s;
            cin>>s;
            for(int j=0;j<n;++j)
            {
                if(s[j]=='1')
                {
                    a[i][j]^=1;
                }
            }
        }
        set <string> h;
        for(int i=0;i<n;++i)
        {
            string s;
            for(int j=0;j<n;++j)
            {
                s+=(a[i][j]+'0');
            }
            h.insert(s);
            if(h.size()>=3) break;
        }
        if(h.size()<=1) cout<<"YES"<<endl;
        else if(h.size()==2)
        {
            string s1=(*h.begin());
            h.erase(h.begin());
            string s2=(*h.begin());
            bool f=true;
            for(int i=0;i<n;++i)
            {
                if(s1[i]==s2[i])
                {
                    f=false;
                }
            }
            if(f) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}