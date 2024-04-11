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

const int maxn = 400015;
int a[maxn];
int pre[maxn], eq[maxn];
int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        memset(eq,0,sizeof(int)*(2*k+2));
        memset(pre,0,sizeof(int)*(2*k+2));
        ii cin >> a[i];
        for(int i=1;i<=n/2;++i) {
            eq[a[i] + a[n+1-i]]++;
            int x = a[i], y = a[n+1-i];
            if(x > y) swap(x, y);
            int l = x + 1, r = y + k;
            pre[r+1]--, pre[l]++;
        }
        for(int i=1;i<=2*k;++i) pre[i]+=pre[i-1];
        int ans = 1e9;
        for(int i=0;i<=2*k;++i) {
            int x0 = eq[i], x1 = pre[i] - eq[i], x2 = n/2 - x0 - x1;
            ans = min(ans, x1 + x2 + x2);
        }
        cout << ans << endl;
    }
}