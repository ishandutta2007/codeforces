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
#define pr(v) for(auto i:v) cout<<i<<",";cout<<endl;
#define prt(a, l, r) for(auto i=l;i<=r;++i) cout<<a[i]<<" ";cout<<endl;
#define pc(x) __builtin_popcount(x)
#define pb push_back
#define PS string qqwwee;cin>>qqwwee;
typedef pair<ll,int> pii;

const int maxn = 1e6+5;
int cnt[maxn];
ll mn[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    memset(mn, 0x3f, sizeof(mn));
    for(int i=2;i<maxn;++i) {
        for(int j=i,c=1;j<maxn;j+=i,++c) {
            if(2*c-1 > i) mn[j] = j;
            else mn[j] = min(mn[j], 1ll*(i-c+1)*i);
        }
    }
    for(int i=2;i<maxn;++i) {
        if(mn[i]<maxn) cnt[mn[i]]++;
    }
    for(int i=1;i<maxn;++i) cnt[i]+=cnt[i-1];
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        cout << n - cnt[n] << '\n';
    }
}