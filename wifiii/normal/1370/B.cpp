#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
#define ii for(int i=1;i<=n;++i)
#define ji for(int j=1;j<=n;++j)
#define jj for(int j=1;j<=m;++j)
#define ij for(int i=1;i<=m;++i)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(),x.end()
#define al(x) x+1,x+1+n
#define asd cout<<"ok"<<endl;
#define asdd cout<<"okok"<<endl;
#define pii pair<int,int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back

const int maxn = 100005;
int a[maxn];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vi v1,v2;
        for(int i=1;i<=2*n;++i) {
            int x;
            cin>>x;
            a[i]=x;
            if(x&1) v1.pb(i);
            else v2.pb(i);
        }
        int cnt=n-1;
        while(cnt && v1.size()>=2) {
            int x=v1.back();v1.pop_back();
            int y=v1.back();v1.pop_back();
            --cnt;
            cout<<x<<" "<<y<<endl;
        }
        while(cnt && v2.size()>=2) {
            int x=v2.back();v2.pop_back();
            int y=v2.back();v2.pop_back();
            --cnt;
            cout<<x<<" "<<y<<endl;
        }
    }
}