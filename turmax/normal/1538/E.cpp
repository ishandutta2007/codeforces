#include <bits/stdc++.h>

using namespace std;
#define int long long
int getans(string s)
{
    int ans=0;
    for(int i=0;i<=((int) s.size())-4;++i)
    {
        if(s.substr(i,4)=="haha") ++ans;
    }
    return ans;
}
pair <string,int> form(pair <string,int> a)
{
    string s=a.first;
    int ans=a.second;
    while(s.size()>=9)
    {
        string t=s;
        t.erase(t.begin()+4);
        ans+=getans(s);ans-=getans(t);
        s=t;
    }
    return {s,ans};
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map <string,pair<string,int> > u;
        for(int i=0;i<n;++i)
        {
            string s;
            cin>>s;
            string h;
            cin>>h;
            if(h==":=")
            {
                string l;
                cin>>l;
                u[s]=form({l,0});
            }
            else
            {
                string s1,s2;
                string s3;
                cin>>s1>>s3>>s2;
                string o=u[s1].first;o+=u[s2].first;
                u[s]=form({o,u[s1].second+u[s2].second});
            }
            if(i==(n-1))
            {
                cout<<getans(u[s].first)+u[s].second<<'\n';
            }
        }
    }
    return 0;
}