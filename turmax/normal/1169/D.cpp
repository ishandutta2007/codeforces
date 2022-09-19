#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int l[n];
    for(int i=0;i<n;++i)
    {
        l[i]=n;
    }
    for(int i=0;i<n;++i)
    {
        for(int j=1;j<=min(n-i-1,i);++j)
        {
            if(s[i-j]==s[i] && s[i]==s[i+j])
            {
                l[i-j]=min(l[i-j],i+j);
                break;
            }
        }
    }
    set <pair<int,int> > h;
    for(int i=0;i<n;++i)
    {
        h.insert({l[i],i});
    }
    long long sum=0;
    for(int i=0;i<n;++i)
    {
        sum+=n-((*h.begin()).first);
        h.erase({l[i],i});
    }
    cout<<sum;
    return 0;
}