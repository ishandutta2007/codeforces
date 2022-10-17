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
    int n, k;
    cin >> n >> k;
    vector<int> a[5001];
    for(int i=1;i<=n;++i) {
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    int ok=1,tp=0;
    vector<int> ans(n+1);
    for(int i=1;i<=5000;++i) {
        if(a[i].size()>k) {
            ok=0;
            break;
        }
        for(int j=0;j<a[i].size();++j) {
            tp=tp%k+1;
            ans[a[i][j]]=tp;
        }
    }
    if(ok) {
        cout<<"YES"<<endl;
        ii cout<<ans[i]<<" ";cout<<endl;
    } else {
        cout<<"NO"<<endl;
    }

}