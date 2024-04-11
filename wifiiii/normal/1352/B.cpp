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

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        int tmp1=k-1,tmp2=2*(k-1);
        if(n-tmp1>0 && (n-tmp1)%2) {
            cout << "YES" << endl;
            for(int i=1;i<k;++i) cout<<1<<" ";
            cout<<n-tmp1<<endl;
        } else if(n-tmp2>0 && (n-tmp2)%2==0) {
            cout << "YES" << endl;
            for(int i=1;i<k;++i) cout<<2<<" ";
            cout<<n-tmp2<<endl;
        } else cout << "NO" << endl;

    }
}