#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define int ll
typedef long double ld;

typedef pair<int,int> pii;
#define x first
#define y second

string solve()
{
    string s;
    cin>>s;
    int cnt[26]={};
    for(char c:s)
        cnt[c-'a']++;
    vector<pair<char,int>> v;
    for(int i=0;i<26;i++)
        if(cnt[i])
            v.push_back({'a'+i,cnt[i]});
    if(v.size()==1)
        return string(v[0].y,v[0].x);
    string ans;
    for(auto&[c,k]:v)
        if(k==1)
        {
            ans+=c,
            k=0;
            break;
        }
    if(ans.size()==1)
    {
        for(auto[c,k]:v)
            ans+=string(k,c);
        return ans;
    }
    if(v[0].y*2-2<=s.size())
    {
        ans=v[0].x;
        v[0].y--;
        for(bool oth=0;v[0].y;oth=!oth)
            if(!oth)
                ans+=v[0].x,
                v[0].y--;
            else
                for(int i=1;i<v.size();i++)
                    if(v[i].y)
                    {
                        ans+=v[i].x;
                        v[i].y--;
                        break;
                    }
        for(auto[c,k]:v)
            ans+=string(k,c);
        return ans;
    }
    ans+=v[0].x;
    v[0].y--;
    ans+=v[1].x;
    v[1].y--;
    if(v.size()==2)
        return ans+string(v[1].y,v[1].x)+string(v[0].y,v[0].x);
    ans+=string(v[0].y,v[0].x);
    v[0].y=0;
    ans+=v[2].x;
    v[2].y--;
    for(auto[c,k]:v)
        ans+=string(k,c);
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    while(t--)
        cout<<solve()<<"\n";
}