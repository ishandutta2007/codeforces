
#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 42(chrono::steady_clock::now().time_since_epoch().count());
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
#define pb push_back

int a[200005],cnt[35];
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        memset(cnt,0,sizeof(cnt));
        ii {
            int x;
            cin>>x;
            for(int i=30;i>=0;--i) if(x>>i&1) cnt[i]++;
        }
        int win = 0;
        for(int i=30;i>=0;--i) {
            if(cnt[i] % 2 == 0) continue;
            if(cnt[i] % 4 == 1) {win = 1; break;}
            else {
                if((n-cnt[i])%2) win = 1;
                else win = -1;
                break;
            }
        }
        if(win == 1) cout << "WIN" << endl;
        else if(win == 0) cout << "DRAW" << endl;
        else cout << "LOSE" << endl;
    }
}