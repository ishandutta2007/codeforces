#include <bits/stdc++.h>

#define fi first
#define se second
#define pb push_back

using namespace std;

void solve()
{
    string s, t;
    cin>>s>>t;
    map<char, vector<int> > mp;
    for (int i=0; i<s.size(); i++)
        mp[s[i]].pb(i);

    vector<pair<int, char> > vec;
    map<char, int> mpx;
    for (char c : t)
        mpx[c]++;
    for (auto t : mpx)
        for (int i=0; i<t.se; i++)
        {
            if (mp[t.fi].empty())
            {
                cout<<"NO\n";
                return;
            }

            vec.pb({mp[t.fi].back(), t.fi});
            mp[t.fi].pop_back();
        }
    sort(vec.begin(), vec.end());
//    reverse(vec.begin(), vec.end());
    string res = "";
    for (auto pa  : vec)
    {
//        cout<<pa.fi<<" "<<pa.se<<"\n";
        res+=pa.se;
    }
//    cout<<res<<" "<<t<<"\n";
    if (res == t)
        cout<<"YES\n";
    else
        cout<<"NO\n";
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin>>T;
    for (int i=1; i<=T; i++)
    {
        solve();
    }
}