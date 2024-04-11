#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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

ll a[100005];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin >> n;
        int c0 = 0;
        vector<ll> pos, neg;
        ii {
            int x;
            cin >> x;
            if(x > 0) pos.push_back(x);
            else if(x < 0) neg.push_back(-x);
            else c0 = 1;
        }
        sort(all(pos));
        sort(all(neg));

        ll ans = -1e18;
        if(c0) ans = 0;
        for(int i=0;i<=5;++i) {
            if(pos.size()>=i && neg.size()>=5-i) {
                int f=(5-i)&1;
                ll tmp=1;
                if(f) {
                    for(int j=0;j<i;++j) tmp=tmp*pos[j];
                    for(int j=0;j<5-i;++j) tmp=tmp*neg[j];
                    ans=max(ans,-tmp);
                } else {
                    reverse(all(pos));
                    reverse(all(neg));
                    for(int j=0;j<i;++j) tmp=tmp*pos[j];
                    for(int j=0;j<5-i;++j) tmp=tmp*neg[j];
                    reverse(all(pos));
                    reverse(all(neg));
                    ans=max(ans,tmp);
                }
            }
        }
        cout << ans << endl;
    }
}