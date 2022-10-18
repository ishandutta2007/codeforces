#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

string f(string s)
{
    string t;
    for(char c:s)
        if(c!='B')
        {
            t+=c;
            while(t.size()>=2&&t[t.size()-1]==t[t.size()-2])
                t.pop_back(),
                t.pop_back();
        }
    int b=0;
    for(char c:s)
        b+=c=='B';
    if(b%2)
        t+='B';
    return t;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        string u,v;
        cin>>u>>v;
        cout<<(f(u)==f(v)?"YES\n":"NO\n");
    }
}