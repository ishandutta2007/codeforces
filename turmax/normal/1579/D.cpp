#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        pair<int,int> a[n];
        set <pair<int,int> > u;
        for(int i=0;i<n;++i) {cin>>a[i].first;a[i].second=i;}
        for(auto h:a) u.insert({-h.first,h.second});
        vector <pair<int,int> > res;
        while(true)
        {
            pair <int,int> o1=*u.begin();u.erase(u.begin());pair <int,int> o2=*u.begin();u.erase(u.begin());
            if(o1.first==0 || o2.first==0) break;
            res.push_back({o1.second,o2.second});
            o1.first++;o2.first++;
            u.insert(o1);u.insert(o2);
        }
        cout<<res.size()<<endl;
        for(auto h:res) cout<<h.first+1<<' '<<h.second+1<<endl;
    }
    return 0;
}