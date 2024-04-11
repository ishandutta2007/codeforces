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
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = (int)3e5 + 5;

int dsu[N];
int col[N];

int dsu_get(int v){
    return v == dsu[v] ? v : dsu[v] = dsu_get(dsu[v]);
}

void dsu_unite(int v, int u){
    v = dsu_get(v);
    u = dsu_get(u);
    if(v != u){
        if(rand()&1)
            swap(v, u);
        dsu[v] = u;
    }
}

void solve(){
    int n, k;
    string s;
    cin >> n >> k >> s;
    iota(dsu, dsu + n, 0);
    fill(col, col + n, -1);
    for(int i = 0; i + k < n; i++)
        dsu_unite(i, i + k);
    for(int i = 0; i < n; i++){
        if(s[i] != '?'){
            int j = dsu_get(i);
            col[j] = s[i] - '0';
        }
    }
    for(int i = 0; i < n; i++){
        int j = dsu_get(i);
        if(col[j] != -1){
            char c = '0' + col[j];
            if(s[i] != '?' && s[i] != c){
                cout << "NO\n";
                return;
            }
            s[i] = c;
        }
    }
    int no = 0;
    int balance = 0;
    for(int i = 0; i < k; i++){
        if(s[i] == '0')++balance;
        else if(s[i] == '1')--balance;
        else ++no;
    }
    no -= abs(balance);
    if(no >= 0 && no%2 == 0)
        cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--)
        solve();
    return 0;
}