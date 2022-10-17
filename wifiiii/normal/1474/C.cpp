#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define al(x) x.begin(),x.end()
#define asd cout<<"ok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pc(x) __builtin_popcount(x)
#define pb push_back

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(2*n), vis(2*n);
        for(int i=0;i<2*n;++i) cin>>a[i];
        sort(a.begin(), a.end());
        int okk = 0;
        for(int i=0;i<2*n-1;++i) {
            unordered_map<int,vector<int>> mp;
            for(int j=0;j<2*n;++j) mp[a[j]].push_back(j), vis[j]=0;
            vis[i]=1;
            vis[2*n-1]=1;
            int cur=a[2*n-1];
            int ok=1;
            vector<pair<int,int>> ans;
            for(int j=2*n-1;j>=0;--j) {
                if(vis[j]) continue;
                vis[j]=1;
                if(!mp.count(cur-a[j])) {
                    ok=0;
                    break;
                }
                auto &v = mp[cur-a[j]];
                while(!v.empty() && vis[v.back()]) v.pop_back();
                if(v.empty()) {
                    ok=0;
                    break;
                }
                vis[v.back()]=1;
                ans.push_back({cur-a[j],a[j]});
                cur=a[j];
            }
            if(ok) {
                int last = a[i];
                cout << "YES\n";
                cout << a[2*n-1] + last << endl;
                cout << a[2*n-1] << " " << last << endl;
                for(auto p : ans) cout << p.first << " " << p.second << endl;
                okk = 1;
                break;
            }
        }
        if(!okk) cout << "NO" << endl;
    }
}