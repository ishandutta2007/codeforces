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
#define asdasd cout<<"okok"<<endl;
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vii vector<pair<int,int>>
#define pr(v) for(auto i:v) cout<<i<<" ";cout<<endl
#define prt(a,l,r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define endl '\n'

int a[55];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        ii a[i]=1<<i;
        int x=0,y=0;
        for(int i=1;i<n/2;++i) x+=a[i];
        for(int i=n/2;i<n;++i) y+=a[i];
        x+=a[n];
        cout<<abs(x-y)<<endl;
    }
}