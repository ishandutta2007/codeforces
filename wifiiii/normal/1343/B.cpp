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
#define vi vector<int>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if(n % 4) {cout << "NO" << endl;}
        else {
            cout<<"YES"<<endl;
            vi ans(n);
            for(int i=0;i<n/2;++i) ans[i]=i*2+2;
            for(int i=0,j=n/2;j<n;++i,++j) ans[j]=i*2+1;
            int sum=0;
            for(int i=0;i<n/2;++i) sum+=ans[i];
            for(int i=n/2;i<n-1;++i) sum-=ans[i];
            ans[n-1]=sum;
            pr(ans);
        }
    }
}