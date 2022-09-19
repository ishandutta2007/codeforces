#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    vector <int> v;
    int l=0;
    while(!s.empty())
    {
        if(s[0]==')')
        {
            s.erase(s.begin());
            ++l;
            continue;
        }
        if(s[s.size()-1]=='(')
        {
            s.erase(s.begin()+s.size()-1);
            continue;
        }
        v.push_back(l);
        v.push_back(l+s.size()-1);
        s.erase(s.begin()+s.size()-1);
        s.erase(s.begin());
        ++l;
    }
    if(!v.empty())
    {
        cout<<1<<endl;
    }
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();++i)
    {
        cout<<v[i]+1<<" ";
    }
    return 0;
}