#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define elif else if
#define sp(x) fixed << setprecision(x)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const double pi = acos(-1.0);
const double EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

set<int> s;
map<int, int> mp;
set<int>::iterator it;
map<int, int>::iterator it2;

void out(){
    if(s.empty()) {cout << 0 << endl; return;}
    it = s.end();
    int ret = (*--it)-(*s.begin());
    it2 = mp.end();
    if(!mp.empty()) ret -= (*--it2).first;
    cout << ret << endl;
}

int main(){
    int N, Q;
    cin >> N >> Q;
    int a[N];
    rep(i, N){
        cin >> a[i];
        s.insert(a[i]);
    }
    sort(a, a+N);
    rep(i, N-1) mp[a[i+1]-a[i]]++;
    out();
    while(Q--){
        int q, x; cin >> q >> x;
        if(q == 0){
            int l = -1, r = -1;
            it = s.upper_bound(x);
            if(it != s.end()){
                r = *it;
                if(--mp[r-x] == 0) mp.erase(r-x);
            }
            if(--it != s.begin()){
                l = *--it;
                if(--mp[x-l] == 0) mp.erase(x-l);
            }
            if(l != -1 && r != -1) mp[r-l]++;
            s.erase(x);
        }
        else{
            if(s.empty()) {s.insert(x); out(); continue;}
            int l = -1, r = -1;
            it = s.upper_bound(x);
            if(it != s.end()){
                r = *it;
                mp[r-x]++;
            }
            if(it != s.begin()){
                l = *--it;
                mp[x-l]++;
            }
            if(l != -1 && r != -1){
                if(--mp[r-l] == 0) mp.erase(r-l);
            }
            s.insert(x);
        }
        out();
    }
}