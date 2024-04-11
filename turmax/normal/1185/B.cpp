#include <bits/stdc++.h>

using namespace std;
#define int long long
pair <vector<int>,vector<char> > to(string s)
{
    char u;
    u=s[0];
    int y;
    y=1;
    vector <int> v1;
    vector <char> v2;
    for(int i=1;i<s.size();++i)
    {
        if(s[i]==u)
        {
            ++y;
        }
        else
        {
            v1.push_back(y);
            y=1;
            v2.push_back(u);
        }
        u=s[i];
    }
    v1.push_back(y);
    v2.push_back(u);
    return make_pair(v1,v2);
}
bool sl(string s,string t)
{
    pair<vector <int>,vector <char> > v1;
    v1=to(s);
    pair<vector <int>,vector <char> > v2;
    v2=to(t);
    if(v1.first.size()!=v2.first.size())
    {
        return false;
    }
    for(int i=0;i<v1.first.size();++i)
    {
        if(v1.second[i]!=v2.second[i])
        {
            return false;
        }
        if(v1.first[i]>v2.first[i])
        {
            return false;
        }
    }
    return true;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    string s;
    string t;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        cin>>t;
        if(sl(s,t)==true)
        {
            cout<<"YES"<<endl;
        }
        else
        {
            cout<<"NO"<<endl;
        }
    }
    return 0;
}