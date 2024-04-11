//
// Created by yamunaku on 2020/01/05.
//

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (n); i++)
#define repl(i, l, r) for(int i = (l); i < (r); i++)
#define per(i, n) for(int i = ((n)-1); i >= 0; i--)
#define perl(i, l, r) for(int i = ((r)-1); i >= (l); i--)
#define all(x) (x).begin(),(x).end()
#define MOD9 998244353
#define MOD1 1000000007
#define IINF 1000000000
#define LINF 1000000000000000000
#define SP <<" "<<
#define CYES cout<<"YES"<<endl
#define CNO cout<<"NO"<<endl
#define CFS cin.tie(0);ios::sync_with_stdio(false)
#define CST(x) cout<<fixed<<setprecision(x)

using ll = long long;
using ld = long double;
using vi = vector<int>;
using mti = vector<vector<int>>;
using vl = vector<ll>;
using mtl = vector<vector<ll>>;
using pi = pair<int, int>;
using pl = pair<ll, ll>;
template<typename T>
using heap = priority_queue<T, vector<T>, function<bool(const T, const T)>>;

mti ans;
mti child;
vi num;
vi c;

void dfs(int x){
    for(auto &nx:child[x]){
        dfs(nx);
        num[x] += num[nx];
        for(auto &y:ans[nx]){
            ans[x].push_back(y);
        }
    }
    if(num[x] - 1 < c[x]){
        CNO;
        exit(0);
    }
    ans[x].insert(ans[x].begin() + c[x], x);
}

int main(){
    // CFS;
    int n;
    cin >> n;
    vi p(n);
    child = mti(n);
    c = vi(n);
    num = vi(n, 1);
    ans = mti(n);
    int r = -1;
    rep(i, n){
        cin >> p[i] >> c[i];
        p[i]--;
        if(p[i] == -1) r = i;
        else child[p[i]].push_back(i);
    }
    dfs(r);
    vi xx(n);
    rep(i, n){
        xx[ans[r][i]] = i + 1;
    }
    CYES;
    rep(i, n){
        cout << xx[i] << " ";
    }
    cout << endl;
    return 0;
}