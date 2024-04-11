#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define nl '\n'
#define vi vector<int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define trav(x,y) for(auto &x:y)
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define P pair
int n, m, k;
const int mxN=1e5,M=998244353,mod=1e9+7;
const ll MOD = 1e9+7;
const ll inf = 8e18;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
 template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
 
 void dbg_out() { cerr << endl; }
 template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
 #define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

int f[200001];
struct o {
    int a;
    o (int a) : a(a) {}
    bool operator<(const o other) const {
        return f[a] == f[other.a] ? a > other.a : f[a] < f[other.a];
    }
    bool operator==(const o other) const {
        return a == other.a;
    }
};
void solve(int test_case = 0) 
{
    int n; cin >> n;	
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i], ++f[a[i]];
    if(n == 1) {
        --f[a[0]];
        cout << 0 << nl;
        return;
    }
    int mxEl = max_element(f, f+n+1) - f;
    //cout << "Maximum element: " << mxEl << nl;
    multiset<o> d;
    for(int i = 1; i <= n; i++)
        for(int j = f[i]; j > 0; --j) {
           d.insert(o(i));
        }
    int ans=0;
    while(d.size()>=2) {
        o tmp=*d.begin();
        if((*d.rbegin()).a!=mxEl)
            break;
        if(tmp==*d.rbegin())
        {
            ++ans;
            break;
        }
        while(tmp == *d.begin()) {
            d.erase(d.begin());
        }
        auto it=d.end();
        --it;
        d.erase(it);
        ++ans;
    }
    rep(i,1,n+1)
        f[i]=0;
    
    cout << ans << "\n";
    

}
int main()
{
	
	//setup();
	cin.tie(0)->sync_with_stdio(0);
	//precalc();
	int T = 1;
		cin >> T;
	for(int nt = 0, i; nt < T; nt++) {
		solve(nt);
		++i;
	}
}