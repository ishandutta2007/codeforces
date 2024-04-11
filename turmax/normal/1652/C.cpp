#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];int w=0;for(int i=0;i<n;++i) {cin>>a[i];w+=a[i];}
        set<pair<int,int> > d;int cyc=0;d.insert({w,cyc});
        map <int,int> cnt;for(int i=0;i<n;++i) cnt[a[i]]++;
        bool ok=true;
        while(!d.empty())
        {
            if(d.size()>n) {ok=false;break;}
            pair<int,int> o=(*d.begin());d.erase(d.begin());int x=o.first;
            if(x==0) {ok=false;break;}
            if(cnt[x]) {cnt[x]--;continue;}
            d.insert({x/2,cyc+1});d.insert({(x+1)/2,cyc+2});cyc+=2;
        }
        cout<<(ok ? "YES" : "NO")<<'\n';
    }
    return 0;
}