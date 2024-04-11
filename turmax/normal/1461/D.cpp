#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <int> ok;
void go(vector <int> v)
{
    if(v.empty()) return;
    int mi=(*min_element(v.begin(),v.end()));
    int ma=(*max_element(v.begin(),v.end()));
    int sum=0;
    for(int i=0;i<v.size();++i) sum+=v[i];
    ok.push_back(sum);
    vector <int> v1,v2;
    int m=(mi+ma)/2;
    for(int i=0;i<v.size();++i)
    {
        if(v[i]<=m) v1.push_back(v[i]);
        else v2.push_back(v[i]);
    }
    if(v1.empty() || v2.empty()) return;
    go(v1);go(v2);
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        ok.clear();
        int n,q;
        cin>>n>>q;
        vector <int> a(n);
        for(int i=0;i<n;++i) cin>>a[i];
        go(a);
        sort(ok.begin(),ok.end());
        while(q--)
        {
            int x;
            cin>>x;
            if(upper_bound(ok.begin(),ok.end(),x)-lower_bound(ok.begin(),ok.end(),x))
            {
                cout<<"Yes"<<'\n';
            }
            else
            {
                cout<<"No"<<'\n';
            }
        }
    }
    return 0;
}