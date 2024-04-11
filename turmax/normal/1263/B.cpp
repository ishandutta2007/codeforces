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
    int n;
    cin>>n;
    vector <string> a(n);
    set <string> b;
    map <int,int> z;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
        if(!b.count(a[i]))
        {
            b.insert(a[i]);
            z[a[i][0]-'0']=1;
        }
    }
    set <string> u;
    for(int i=0;i<n;++i)
    {
        if(u.count(a[i]))
        {
            for(int j=0;j<=9;++j)
            {
                if(!z.count(j))
                {
                    a[i][0]=('0'+j);
                    z[j]=1;
                    break;
                }
            }
        }
        u.insert(a[i]);
    }
    cout<<(n-b.size())<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<a[i]<<endl;
    }
    }
    return 0;
}