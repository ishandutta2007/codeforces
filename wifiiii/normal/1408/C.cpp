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

const int maxn = 100005;
const double eps = 1e-8;
int a[maxn];
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n,l;
        cin>>n>>l;
        for(int i=1;i<=n;++i) cin>>a[i];a[n+1]=l;
        double lo=0,hi=l;
        for(int i=1;i<=100;++i) {
            double mid=(lo+hi)/2;
            double t1=0,t2=0;
            for(int i=1;i<=n+1;++i) {
                t1 += (min((double)a[i],mid)-a[i-1])/i;
                if(a[i] >= mid) break;
            }
            for(int i=n;i>=0;--i) {
                t2 += (a[i+1]-max((double)(a[i]),mid))/(n-i+1);
                if(a[i] <= mid) break;
            }
            if(t1 <= t2) lo = mid;
            else hi = mid;
        }
        double t1=0;
        for(int i=1;i<=n+1;++i) {
            t1 += (min((double)a[i],lo)-a[i-1])/i;
            if(a[i] >= lo) break;
        }
        cout << fixed << setprecision(8) << t1 << endl;
    }
}