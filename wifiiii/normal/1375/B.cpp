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

int a[1005][1005];
int dir1[] = {-1,1,0,0};
int dir2[] = {0,0,1,-1};
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        ii jj cin>>a[i][j];
        auto chk = [&](int i,int j) {
            return i>=1 && j>=1 && i<=n && j<=m;
        };
        int ok=1;
        ii jj {
            int cnt=0;
            for(int k=0;k<4;++k) {
                int x=i+dir1[k],y=j+dir2[k];
                if(chk(x,y)) ++cnt;
            }
            if(a[i][j]>cnt) {ok=0;break;}
            a[i][j]=cnt;
        }
        if(ok) {
            cout<<"YES"<<endl;
            ii {jj cout<<a[i][j]<<" ";cout<<endl;}
        }
        else cout<<"NO"<<endl;
    }
}