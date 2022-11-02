//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

const int N = 1002;

vector<pii> ans;
int n;
pii a[N];
int backinv[N];
vector<int> inv[N];

void solve(){
    cin >> n;
    map<int, int> fuck_this_problem;
    for(int i = 0; i < n; i++){
        cin >> a[i].X;
        if(fuck_this_problem.count(a[i].X)){
            a[i] = {a[i].X, fuck_this_problem[a[i].X]};
            ++fuck_this_problem[a[i].X];
        }
        else{
            a[i] = {a[i].X, 0};
            fuck_this_problem[a[i].X] = 1;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i] > a[j]){
                inv[j].push_back(i);
            }
        }
    }
    for(int i = n - 1; i >= 0; i--){
        sort(all(inv[i]), [&](int l, int r){return a[l] < a[r];});
        for(int j: inv[i]){
            swap(a[j], a[i]);
            ans.emplace_back(j + 1, i + 1);
        }
    }
    cout << ans.size() << endl;
    for(auto [i, j]: ans)
        cout << i << ' ' << j << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(T--)
        solve();
    return 0;
}