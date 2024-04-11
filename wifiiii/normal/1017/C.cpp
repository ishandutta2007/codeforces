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
    int n;
    cin>>n;
    int ans=1e9,a=0,b=0;
    for(int i=1;i<=n;++i) {
        int x=(n+i-1)/i;
        if(i+x < ans) {
            ans=i+x;
            a=i;
            b=x;
        }
    }
//    cout<<ans<<" "<<a<<" "<<b<<endl;
    int tp=0;
    vector<vector<int>> res;
    for(int i=1;i<=a;++i) {
        vector<int> v;
        for(int j=1;j<=b;++j) {
            v.push_back(++tp);
            if(tp == n) break;
        }
        res.push_back(v);
    }
    reverse(all(res));
    for(auto p:res) {
        for(int i:p) {
            cout<<i<<" ";
        }
    }
    cout<<endl;
}