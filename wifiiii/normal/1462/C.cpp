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
typedef pair<int, int> pii;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int x;
        cin>>x;
        vi v(9);
        iota(all(v),1);
        int ans=1e9;
        for(int i=0;i<1<<9;++i) {
            int s=0,c=0;
            for(int j=0;j<9;++j) if(i>>j&1) s+=v[j],c=c*10+v[j];
            if(s==x) {
                ans=min(ans,c);
            }
        }
        if(ans==1e9) cout<<-1<<endl;
        else cout<<ans<<endl;
    }
}