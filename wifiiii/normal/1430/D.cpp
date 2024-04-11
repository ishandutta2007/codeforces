#include<bits/stdc++.h>

typedef long long ll;
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

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        n=s.size();
        int cnt=1;
        vector<int> v;
        for(int i=0;i<n;++i) {
            if(i+1<n && s[i]==s[i+1]) {
                ++cnt;
            } else {
                v.push_back(cnt);
                cnt=1;
            }
        }
        int ans=0,cur=0;
        for(int i=0;i<v.size();++i) {
            cur=max(cur,i);
            while(cur<v.size() && v[cur]<=1) {
                ++cur;
            }
            if(cur<v.size()) {
                --v[cur];
            } else {
                ++i;
            }
            ++ans;
        }
        cout<<ans<<endl;
    }
}
// 1000010 -> 3
// 1010000 -> 4