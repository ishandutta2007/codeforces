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
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

ll a[30][30];
vector<pii> b[60];
int main() {
    int n;
    cin>>n;
    ii ji b[i+j-2].pb({i,j});
    for(int i=0;i<2*n-1;++i) {
        sort(all(b[i]));
        int f=0;
        for(auto p:b[i]) {
            a[p.first][p.second]=f*(1ll<<i);
            f^=1;
        }
    }
    ii {ji cout<<a[i][j]<<" ";cout<<endl;}
    int q;
    cin>>q;
    while(q--) {
        ll k;
        cin>>k;
        int x=1,y=1;
        ll cur=0;
        cout<<1<<" "<<1<<endl;
        while(x+y != 2*n) {
            int bit=x+y;
            ll mask=(1ll<<bit)-1;
            if(x+1<=n && y+1<=n) {
                if((k&mask) == (cur+a[x+1][y])) {
                    cur+=a[x+1][y];
                    ++x;
                }  else {
                    cur+=a[x][y+1];
                    ++y;
                }
            } else if(x+1 <= n) {
                ++x;
            } else if(y+1 <= n) {
                ++y;
            }
            cout<<x<<" "<<y<<endl;
        }
    }
}