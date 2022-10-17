
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 42(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdasd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        int n=s.size();
        vi cnt(10);
        for(char c:s) cnt[c-'0']++;
        int mx=0;
        for(int i=0;i<10;++i) mx=max(mx,cnt[i]);
        int ans=n-mx;
        for(int i=0;i<10;++i) {
            for(int j=0;j<10;++j) {
                if(i == j) continue;
                int f = 0, len = 0;
                for(int k=0;k<s.size();++k) {
                    if(f == 0 && i == s[k]-'0') {
                        f = 1;
                    } else if(f == 1 && j == s[k]-'0') {
                        f = 0;
                        len += 2;
                        ans = min(ans, n-len);
                    }
                }
            }
        }
        cout << ans << endl;
    }
}