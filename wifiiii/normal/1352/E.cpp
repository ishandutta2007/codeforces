#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
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
#define endl '\n'

int a[10005],c[10005];
int main() {
    int t;
    cin>>t;
    while(t--) {
        memset(c,0,sizeof(c));
        int n;
        cin>>n;
        ii cin>>a[i],c[a[i]]++;
        int ans=0;
        for(int i=1;i<=n;++i) {
            int tmp=a[i];
            for(int j=i+1;j<=n;++j) {
                tmp+=a[j];
                if(tmp > n) break;
                ans+=c[tmp];
                c[tmp]=0;
            }
        }
        cout<<ans<<endl;
    }
}