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
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)1e5 + 5;

int curr = 0;
bool used[N];
vector<int> gr[N];
int n, k;

void dfs(int v){
    used[v] = 1;
    ++curr;
    I(u, gr[v])
        if(!used[u])
            dfs(u);
}

int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
    cin >> n >> k;
    F(i, 0, k){
        int v, u;
        cin >> v >> u;
        --v; --u;
        gr[v].pb(u); gr[u].pb(v);
    }
    int ans = 0;
    F(i, 0, n){
        if(used[i])cont;
        curr = 0;
        dfs(i);
        ans += curr - 1;
    }
    cout << k - ans << endl;
    return 0;
}