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
        int a[n];
        for(int i=0;i<n;++i) cin>>a[i];
        int cnt[n+2]={0};
        for(auto h:a) cnt[h]++;
        int pos=0;
        for(int i=0;;++i) if(!cnt[i]) {pos=i;break;}
        vector <int> ans;
        int cur=0;
        set <int> ze;
        ze.insert(pos);
        while(cur!=n)
        {
            set<int> o;
            bool ok=true;
            for(int i=cur;i<n;++i)
            {
                cnt[a[i]]--;++cur;
                if(!cnt[a[i]]) ze.insert(a[i]);
                if(a[i]<pos) o.insert(a[i]);
                if(o.size()==pos)
                {
                    ans.push_back(pos);
                    o.clear();
                    pos=(*ze.begin());
                    ok=false;
                    break;
                }
            }
            //if(!ok) break;
        }
        cout<<ans.size()<<'\n';
        for(auto h:ans) cout<<h<<' ';
        cout<<'\n';
    }
    return 0;
}