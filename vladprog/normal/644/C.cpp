#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    map<string,set<string>> m1;
    while(n--)
    {
        string s;
        cin>>s;
        int pos=0;
        for(int cnt=0;pos<s.size();pos++)
            if((cnt+=s[pos]=='/')==3)
                break;
        m1[s.substr(0,pos)].insert(s.substr(pos));
    }
    map<set<string>,set<string>> m2;
    for(auto p:m1)
        m2[p.second].insert(p.first);
    int ans=0;
    for(auto p:m2)
        if(p.second.size()>1)
            ans++;
    cout<<ans<<"\n";
    for(auto p:m2)
        if(p.second.size()>1)
        {
            for(string s:p.second)
                cout<<s<<" ";
            cout<<"\n";
        }
}