#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    int next[n];
    int curr;
    next[n-1]=1e9;
    int t[n];
    t[n-1]=1e9;
    curr=1e9;
    for(int i=(n-2);i>=0;--i)
    {
        if(s[i]==s[i+1])
        {
            next[i]=curr;
            t[i]=t[i+1];
        }
        else
        {
            curr=(i+1);
            next[i]=curr;
            if(next[i+1]==1e9 || s[next[i+1]]==s[i])
            {
                t[i]=t[i+1];
            }
            else
            {
                t[i]=next[i+1];
            }
        }
    }
    int q;
    cin>>q;
    for(int i=0;i<q;++i)
    {
    int l,r;
    cin>>l>>r;
    l--;
    if((r-l)==1)
    {
        cout<<"Yes"<<endl;
        continue;
    }
    if(next[l]>=r || (t[l]>=r && s[l]==s[r-1]))
    {
        cout<<"No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    }
    return 0;
}