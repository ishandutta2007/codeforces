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
    vector <pair<char,int> > h;
    char l;
    int curr;
    for(int i=0;i<s.size();++i)
    {
        if(i==0) {l=s[i];curr=1;continue;}
        if(s[i]==l)
        {
            ++curr;
        }
        else
        {
            h.push_back({l,curr});
            l=s[i];
            curr=1;
        }
    }
    h.push_back({l,curr});
    if(h.back().first==h[0].first && h.size()!=1)
    {
        h[0].second+=h.back().second;
        h.pop_back();
    }
    if(h.size()==1) {cout<<(h[0].second+2)/3<<endl;continue;}
    int sum=0;
    for(int i=0;i<h.size();++i)
    {
        sum+=(h[i].second/3);
    }
    cout<<sum<<endl;
    }
    return 0;
}