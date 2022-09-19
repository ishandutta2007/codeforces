#include <bits/stdc++.h>

using namespace std;
#define int long long
string h;
vector <pair<int,string> > vans;
void getans()
{
    pair <int,string> ans;
    ans.first=h.size();
    if(h.size()>10)
    {
        for(int i=0;i<2;++i) ans.second+=h[i];
        ans.second+="...";
        for(int i=h.size()-5;i<=h.size()-1;++i)
        {
            ans.second+=h[i];
        }
        reverse(ans.second.begin(),ans.second.end());
    }
    else
    {
        reverse(h.begin(),h.end());
        ans.second=h;
        reverse(h.begin(),h.end());
    }
    vans.push_back(ans);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    string z;
    bool can=true;
    for(int i=(n-1);i>=0;i--)
    {
        char u=s[i];
        if((i==(n-1) || s[i]!=s[i+1] || !can) || (h.empty() || u!=h.back()))
        {
            if(h.empty() || h.back()!=u)
            {
                z+=u;
            }
            h+=u;
            can=true;
        }
        else
        {
            if(z.size()>=2 && z[z.size()-2]>z[z.size()-1])
            {
                h+=u;
                can=true;
            }
            else
            {
                h.pop_back();
                if(h.back()!=z[z.size()-1])
                {
                    z.pop_back();
                }
                can=false;
            }
        }
        getans();
    }
    reverse(vans.begin(),vans.end());
    for(auto h:vans)
    {
        cout<<h.first<<' '<<h.second<<endl;
    }
    return 0;
}