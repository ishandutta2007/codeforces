// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
#pragma GCC optimize("O2")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
// #define i128 long long
#define double long double
using namespace std;
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={1,1,2,2,-1,-1,-2,-2};
int dy[]={2,-2,1,-1,2,-2,1,-1};
const int mod=1e9+7;
const int INF=LLONG_MAX/5000;
const double EPS=1e-9;
// const int MAXN=2003*2003;
const int N=200003;
const int K=360*10000;
mt19937 rng(1234);



int n,q;
int a[N],b[N],cnt[N];

vi topoSort(const vector<vi>& gr) {
	vi indeg(sz(gr)), ret;
	for (auto& li : gr) for (int x : li) indeg[x]++;
	queue<int> q; // use priority_queue for lexic. largest ans.
	rep(i,sz(gr)) if (indeg[i] == 0) q.push(i);
	while (!q.empty()) {
		int i = q.front(); // top() for priority queue
		ret.push_back(i);
		q.pop();
		for (int x : gr[i])
			if (--indeg[x] == 0) q.push(x);
	}
	return ret;
}
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15), cerr.precision(15);
    int _;
    cin>>_;
    while (_--){
        cin>>n;
        vector<vi> g(n);
        rep(i,n) cnt[i]=0;
        rep(i,n) cin>>a[i], a[i]--;
        rep(i,n) cin>>b[i], b[i]--;
        rep(i,n) cnt[a[i]]++;
        int mx=-1, idx=-1;
        rep(i,n) if (cnt[i]>mx) mx=cnt[i], idx=i;
        rep(i,n){
            if (a[i]==idx||b[i]==idx) continue;
            g[a[i]].pb(b[i]);
        }
        auto ret=topoSort(g);
        if (sz(ret)==n) cout<<"AC\n";
        else cout<<"WA\n";
    }
    
    return 0;
}