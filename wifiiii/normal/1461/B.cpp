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

char a[505][505];
int r[505][505], l[505][505];
// 26166750
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        ii jj cin>>a[i][j];
        int ans=0;
        for(int i=1;i<=n;++i) {
            int lst=0;
            for(int j=1;j<=m;++j) {
                if(a[i][j]=='.') lst=j;
                l[i][j]=lst;
            }
            int nxt=m+1;
            for(int j=m;j>=1;--j) {
                if(a[i][j]=='.') nxt=j;
                r[i][j]=nxt;
            }
        }
        ii jj {
                if(a[i][j]!='*') continue;
                ++ans;
                for(int k=2;k<=n;++k) {
                    if(i+k-1>n || j-k+1<1 || j+k-1>m) break;
                    int ok=1;
                    if(r[i+k-1][j]>j+k-1 && l[i+k-1][j]<j-k+1);
                    else ok=0;
                    if(!ok) break;
                    ++ans;
                }
            }
        cout<<ans<<endl;
    }
}