#include<bits/stdc++.h>

typedef long long ll;
typedef long double ld;
using namespace std;
//mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 mrand(42);
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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<int,int> pii;

int a[100005];
int cnt[200005],mx[200005],mx2[200005];

int main() {
    int n;
    cin >> n;
    ii cin >> a[i];
    memset(mx, 0x3f,sizeof(mx));
    memset(mx2, 0x3f,sizeof(mx2));
    for(int i=1;i<=n;++i) {
        int x = a[i];
        for(int j=2;j*j<=x;++j) {
            if(x % j == 0) {
                int p = 0;
                while(x % j == 0) x/=j,p++;
                cnt[j]++;
                if(p < mx[j]) {
                    mx2[j] = mx[j];
                    mx[j] = p;
                } else if(p < mx2[j]) {
                    mx2[j] = p;
                }
            }
        }
        if(x > 1) {
            cnt[x]++;
            if(1 < mx[x]) {
                mx2[x] = mx[x];
                mx[x] = 1;
            } else if(1 < mx2[x]) {
                mx2[x] = 1;
            }
        }
    }
    ll ans = 1;
    for(int i=2;i<=200000;++i) {
        if(cnt[i]) {
            int res = n - cnt[i];
            if(res < 2) {
                int k = 0;
                if(res == 1) k = mx[i];
                else k = mx2[i];
                for(int j=1;j<=k;++j) ans = ans * i;
            }
        }
    }
    cout << ans << endl;
}