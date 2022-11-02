//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;

int n, k, p;
vector<int> gr[N];
int lst[N];
ll pref[N];
int sz = 0;

void dfs(int v, int d = 0, int pr = -1){
    lst[sz++] = d;
    I(u, gr[v]){
        if(u != pr)
            dfs(u, d + 1, v);
    }
}

bool can(int x){
    if(x > k)ret false;
    F(i, max(1, x), n){
        ll val = lst[i] * 1ll * x;
        val -= pref[i] - pref[i - x];
        if(val <= p)ret true;
    }
    ret false;
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> k >> p;
    F(i, 0, n - 1){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].pb(u);
        gr[u].pb(v);
    }
    dfs(0);
    sort(lst, lst + n);
    pref[0] = lst[0];
    F(i, 1, n){
        pref[i] = pref[i - 1] + lst[i];
    }
    int L = 0, R = min(n, k + 1);
    while(R - L > 1){
        int mid = (L + R)/2;
        if(can(mid))
            L = mid;
        else
            R = mid;
    }
    cout << L << endl;
	return 0;
}