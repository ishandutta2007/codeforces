#include<bits/stdc++.h>

typedef long long ll;
typedef long long LL;
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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#define D(x...) cerr << "[" << #x << "] = ["; _print(x)

inline ll calc(ll n, ll k) {
    ll x=n/k, y=x+1, b=n%k, a=k-b;
    return a*x*x+b*y*y;
}

int a[100005],cnt[100005];
struct node {
    int w, cnt;
    bool operator < (const node & n) const {
        return calc(w, cnt) - calc(w, cnt+1) < calc(n.w, n.cnt) - calc(n.w, n.cnt+1);
    }
};
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+1+n);
    memset(cnt, 0, sizeof(cnt));
    priority_queue<node> q;
    for(int i=1;i<=n;++i) q.push({a[i], 1});
    for(int i=1;i<=k-n;++i) {
        node cur = q.top(); q.pop();
        cur.cnt++;
        q.push(cur);
    }
    ll ans=0;
    while(!q.empty()) {
        node cur=q.top(); q.pop();
        ans+=calc(cur.w, cur.cnt);
    }
    cout << ans << endl;
}