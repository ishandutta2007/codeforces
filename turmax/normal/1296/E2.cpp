#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector <int> z(1);
    set <pair<int,int> > u;
    z[0]=0;
    u.insert({0,0});
    vector <int> a(n);
    set <pair<int,int> >::iterator it;
    for(int i=0;i<n;++i)
    {
        if((s[i]-'a')<z[z.size()-1])
        {
            u.insert({s[i]-'a',z.size()});
            z.push_back(s[i]-'a');
            a[i]=z.size()-1;
        }
        else
        {
            it=u.upper_bound({s[i]-'a',1e18});
            it--;
            pair <int,int> o=(*it);
            u.erase(o);
            a[i]=o.second;
            u.insert({s[i]-'a',o.second});
            z[o.second]=(s[i]-'a');
        }
    }
    int ma=*max_element(a.begin(),a.end());
    cout<<ma+1<<endl;
    //cout<<" tgrfedw "<<endl;
    for(int i=0;i<n;++i)
    {
        cout<<a[i]+1<<" ";
    }
    return 0;
}