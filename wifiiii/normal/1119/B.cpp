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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

int a[1005];

int main() {
    int n,h;
    cin>>n>>h;
    for(int i=1;i<=n;++i) cin>>a[i];
    for(int k=1;k<=n;++k) {
        sort(a+1,a+1+k);
        int cur=0;
        if(k&1) for(int i=1;i<=k;i+=2) cur+=a[i];
        else for(int i=2;i<=k;i+=2) cur+=a[i];
        if(cur>h) return cout<<k-1<<endl,0;
    }
    cout<<n<<endl;
}