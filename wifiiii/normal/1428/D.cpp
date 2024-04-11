#include<bits/stdc++.h>

typedef long long ll;
typedef long long LL;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 mrand(42);
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

vector<int> cnt[4];
int pos[100005], pos2[100005];
int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> ans;
    int tp=n+1;
    for(int i=1;i<=n;++i) {
        int x;
        cin>>x;
        if(x == 0) continue;
        else if(x == 1) {
            if(cnt[2].size()) {
                int cur = cnt[2].back();
                cnt[2].pop_back();
                ans.push_back({cur, pos[cur]});
                ans.push_back({i, pos[cur]});
            } else if(cnt[3].size()){
                int cur = cnt[3].back();
                cnt[3].pop_back();
                ans.push_back({cur, pos[cur]});
                ans.push_back({i, pos[cur]});
                ans.push_back({i, pos2[cur]});
            } else {
                --tp;
                ans.push_back({i, tp});
            }
        } else if(x == 2) {
            if(cnt[3].size()) {
                int cur = cnt[3].back();
                cnt[3].pop_back();
                ans.push_back({cur, pos[cur]});
                ans.push_back({i, pos[cur]});
                cnt[2].push_back(i);
                pos[i] = pos2[cur];
            } else {
                --tp;
                cnt[2].push_back(i);
                pos[i] = tp;
            }
        } else {
            if(cnt[3].size()) {
                int cur = cnt[3].back();
                cnt[3].pop_back();
                ans.push_back({cur, pos[cur]});
                ans.push_back({i, pos[cur]});
                cnt[3].push_back(i);
                pos[i] = pos2[cur];
                --tp;
                pos2[i] = tp;
            } else {
                --tp;
                cnt[3].push_back(i);
                pos[i] = tp;
                --tp;
                pos2[i] = tp;
            }
        }
        if(tp<=0) break;
    }
    if(cnt[2].size() || cnt[3].size() || tp<=0) {
        cout << -1 << endl;
    } else {
        assert(ans.size() <= 2 * n);
        cout << ans.size() << endl;
        for(auto p : ans) cout << n+1-p.second << " " << p.first << endl;
    }
}