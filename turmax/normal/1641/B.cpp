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
        int n;cin>>n;vector<int> a(n);for(int i=0;i<n;++i) cin>>a[i];
        map <int,int> cnt;for(auto h:a) cnt[h]++;
        bool ok=true;
        for(auto h:a) if(cnt[h] & 1) {cout<<-1<<'\n';ok=false;break;}
        if(!ok) continue;
        vector <pair<int,int> > ans;vector <int> res;
        int cur=0;
        while(!a.empty())
        {
            for(int pos=1;pos<a.size();++pos)
            {
                if(a[pos]==a[0])
                {
                    res.push_back(2*pos);
                    for(int j=pos+1;j<2*pos;++j) ans.push_back({cur+j,a[j-pos]});
                    a.erase(a.begin()+pos);a.erase(a.begin());reverse(a.begin(),a.begin()+pos-1);
                    cur+=2*pos;
                    break;
                }
            }
        }
        cout<<ans.size()<<'\n';
        for(auto h:ans) cout<<h.first<<' '<<h.second<<'\n';
        cout<<res.size()<<'\n';
        for(auto h:res) cout<<h<<' ';
        cout<<'\n';
    }
    return 0;
}