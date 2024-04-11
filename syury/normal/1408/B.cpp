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
typedef long double dbl;
typedef pair<int, int> pii;

const int N = 200;

int n, K;
int a[N];
int b[N][N];
int dist[N];

void solve(){
    cin >> n >> K;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    if(K == 1){
        for(int i = 1; i < n; i++)
            if(a[i] != a[0]){cout << "-1\n"; return;}
        cout << "1\n";
        return;
    }
    int m = 1;
    for(int i = 0; i < n + 3; i++){
        dist[i] = 0;
        fill(b[i], b[i] + n, 0);
    }
    b[0][0] = a[0];
    dist[0] = 1;
    for(int i = n - 1; i >= 0; i--)
        a[i] -= a[0];
    for(int i = 1; i < n; i++){
        int pos = m;
        for(int k = 0; k < m; k++){
            b[k][i] = b[k][i - 1];
            if(dist[k] < K){
                pos = k;
            }
        }
        if(!a[i])
            continue;
        if(pos == m){
            dist[pos] = 1;
            ++m;
        }
        ++dist[pos];
        b[pos][i] += a[i];
        for(int j = i + 1; j < n; j++){
            a[j] -= a[i];
        }
    }
    //for(int i = 0; i < m; i++)for(int j = 0; j < n; j++){cout << b[i][j] << " \n"[j + 1 == n];}
    cout << m << '\n';
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