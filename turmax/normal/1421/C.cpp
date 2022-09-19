#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    vector <pair<char,int> > v;
    int sz=s.size();
    v.push_back({'L',2});
    ++sz;
    v.push_back({'L',2});
    ++sz;
    v.push_back({'L',2});
    ++sz;
    v.push_back({'R',2});
    sz*=2;sz-=2;
    v.push_back({'R',sz-1});
    cout<<v.size()<<endl;
    for(auto h:v)
    {
        cout<<h.first<<' '<<h.second<<endl;
    }
    return 0;
}