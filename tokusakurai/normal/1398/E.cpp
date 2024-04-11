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
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
const ld EPS = 1e-10;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

set<ll> sa, sb, s, sub;
ll a = 0, b = 0, c = 0;

void insert(int q, ll x){
    if(q == 0){
        a += x, sa.insert(x);
        c += x, s.insert(x);
        c -= *s.begin(), sub.insert(*s.begin()), s.erase(*s.begin());
    }
    else{
        b += x, sb.insert(x);
        sub.insert(x);
        c += *sub.rbegin(), s.insert(*sub.rbegin()), sub.erase(*sub.rbegin());
    }
}

void remove(int q, ll x){
    if(q == 0){
        a -= x, sa.erase(x);
        if(sub.count(x)) sub.erase(x);
        else{
            c -= x, s.erase(x);
            c += *sub.rbegin(), s.insert(*sub.rbegin()), sub.erase(*sub.rbegin());
        }
    }
    else{
        b -= x, sb.erase(x);
        if(s.count(x)) c -= x, s.erase(x);
        else{
            sub.erase(x);
            c -= *s.begin(), sub.insert(*s.begin()), s.erase(*s.begin());
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;
    sa.insert(0), sub.insert(0);
    while(Q--){
        int q; ll x;
        cin >> q >> x;
        if(x > 0) insert(q, x);
        else remove(q, -x);
        if(sb.empty() || *sb.begin() < *sa.rbegin()) cout << a+b+c << endl;
        else cout << a+b+c-*sb.begin()+*sa.rbegin() << endl;
    }
}