#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<pair<vector<int>,int>> a(m);
        for(int i=0;i<m;++i) {
            int k;
            cin>>k;
            while(k--) {
                int x;
                cin>>x;
                a[i].first.push_back(x);
                a[i].second=i;
            }
        }
        sort(a.begin(),a.end(),[&](auto &i,auto &j){return i.first.size()<j.first.size();});
        vector<int> ans(m),cnt(n+1);
        cnt[0]=1e9;
        for(int i=0;i<m;++i) {
            int mn=0;
            for(int j:a[i].first) {
                if(cnt[j]<cnt[mn]) {
                    mn=j;
                }
            }
            cnt[mn]++;
            ans[a[i].second]=mn;
        }
        int lim=(m+1)/2;
        int ok=1;
        for(int i=1;i<=n;++i) if(cnt[i]>lim) ok=0;
        if(ok) {
            cout<<"YES"<<endl;
            for(int i=0;i<m;++i) cout<<ans[i]<<" ";
            cout<<endl;
        } else {
            cout<<"NO\n";
        }
    }
}