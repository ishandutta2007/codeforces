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
    int t;
    cin>>t;
    while(t--) {
        int x, y;
        cin >> x >> y;
        ll c1,c2,c3,c4,c5,c6;
        cin>>c1>>c2>>c3>>c4>>c5>>c6;
        for(int i=1;i<=100;++i) {
            c1=min(c1,c6+c2);
            c2=min(c2,c1+c3);
            c3=min(c3,c2+c4);
            c4=min(c4,c3+c5);
            c5=min(c5,c4+c6);
            c6=min(c6,c5+c1);
        }
        ll ans=0;
        if(y>=x && x>=0) {
            int cc1=x,cc2=y-x;
            ans=cc1*c1+cc2*c2;
        } else if(x>=y && y>=0) {
            int cc1=y,cc6=x-y;
            ans=cc1*c1+cc6*c6;
        } else if(x>=0 && y<=0) {
            int cc6=x,cc5=-y;
            ans=cc5*c5+cc6*c6;
        } else if(x<=0 && y<=0 && x>=y) {
            int cc4=-x,cc5=x-y;
            ans=cc5*c5+cc4*c4;
        } else if(x<=0 && y<=0 && x<=y) {
            int cc3=y-x,cc4=-y;
            ans=cc3*c3+cc4*c4;
        } else {
            int cc3=-x,cc2=y;
            ans=cc3*c3+cc2*c2;
        }
        cout<<ans<<endl;
    }
}