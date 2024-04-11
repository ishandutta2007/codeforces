#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    int a[n];
    int b[n];
    int c[n];
    int k;
    for(int i=0;i<n;++i)
    {
        cin>>k;
        k--;
        a[i]=k;
    }
    for(int i=0;i<n;++i)
    {
        cin>>k;
        k--;
        b[i]=k;
    }
    for(int i=0;i<n;++i)
    {
        c[b[i]]=i;
    }
    char t='a';
    string s;
    int ma=-1;
    for(int i=0;i<n;++i)
    {
        s+=t;
        ma=max(ma,c[a[i]]);
        if(ma==i)
        {
            if(t!='a'+m-1)
            {
                ++t;
            }
        }
    }
    string h;
    for(int i=0;i<n;++i)
    {
        h+=' ';
    }
    for(int i=0;i<n;++i)
    {
        h[a[i]]=s[i];
    }
    if(s[s.size()-1]>=('a'+m-1))
    {
        cout<<"YES"<<endl;
        cout<<h;
    }
    else
    {
        cout<<"NO";
    }
    return 0;
}