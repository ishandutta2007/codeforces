#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    string s,t;
    cin>>s>>t;
    string p;
    for(int i=0;i<n;i++)
        if(s[i]!=t[i])
            p+=s[i];
    if(count(p.begin(),p.end(),'0')!=
       count(p.begin(),p.end(),'1'))
        cout<<-1,exit(0);
    vector<pair<char,int>> v;
    for(char c:p)
        if(v.empty()||v.back().x!=c)
            v.push_back({c,1});
        else
            v.back().y++;
    int ans=0;
    while(!v.empty())
    {
        ans++;
        if(v.size()%2)
            v.front().y+=v.back().y,
            v.pop_back();
        vector<pair<char,int>> v1;
        for(auto el:v)
        {
            el.y--;
            if(!el.y)
                continue;
            if(v1.empty()||v1.back().x!=el.x)
                v1.push_back(el);
            else
                v1.back().y+=el.y;
        }
        v=v1;
    }
    cout<<ans;
}