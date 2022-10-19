#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

struct query{
    int l, r, id;
    query(int l, int r, int id) : l(l), r(r), id(id) {}
};

int MAX = 100000;
 
template<typename T, typename Q>
struct Mo{
    vector<T> a;
    const int n;
    int l, r;
    vector<deque<int>> que;
    vector<vector<ll>> s;
    vector<int> p, q;
    Q sp, sq;
 
    Mo(vector<T> a) : a(a), n(a.size()), l(0), r(0), que(MAX), s(3, vector<ll>(MAX, 0)), p(MAX), q(MAX), sp(0), sq(0) {}

    bool judge(ll x, ll y, ll z){
        if(x == 0) return true;
        if(y%x != 0) return false;
        ll k = y/x;
        return z == k*k*x;
    }
 
    void add_left(int i){
        T x = a[i];
        if(que[x].empty()){
            que[x].push_front(i), p[x]++, q[x]++, sp++, sq++;
        }
        else{
            ll d = que[x].front()-i, now = 1;
            rep(j, 3){
                s[j][x] += now, now *= d;
            }
            que[x].push_front(i), p[x]++;

            if(q[x] == 1){
                if(!judge(s[0][x], s[1][x], s[2][x])){
                    q[x]--, sq--;
                }
            }
        }
    }

    void add_right(int i){
        T x = a[i];
        if(que[x].empty()){
            que[x].push_back(i), p[x]++, q[x]++, sp++, sq++;
        }
        else{
            ll d = i-que[x].back(), now = 1;
            rep(j, 3){
                s[j][x] += now, now *= d;
            }
            que[x].push_back(i), p[x]++;

            if(q[x] == 1){
                if(!judge(s[0][x], s[1][x], s[2][x])){
                    q[x]--, sq--;
                }
            }
        }
    }
 
    void erase_left(int i){
        T x = a[i];
        if(sz(que[x]) == 1){
            que[x].pop_front(), p[x]--, q[x]--, sp--, sq--;
        }
        else{
            que[x].pop_front(), p[x]--;
            ll d = que[x].front()-i, now = 1;
            rep(j, 3){
                s[j][x] -= now, now *= d;
            }

            if(q[x] == 0){
                if(judge(s[0][x], s[1][x], s[2][x])){
                    q[x]++, sq++;
                }
            }
        }
    }

    void erase_right(int i){
        T x = a[i];
        if(sz(que[x]) == 1){
            que[x].pop_back(), p[x]--, q[x]--, sp--, sq--;
        }
        else{
            que[x].pop_back(), p[x]--;
            ll d = i-que[x].back(), now = 1;
            rep(j, 3){
                s[j][x] -= now, now *= d;
            }

            if(q[x] == 0){
                if(judge(s[0][x], s[1][x], s[2][x])){
                    q[x]++, sq++;
                }
            }
        }
    }
 
    vector<Q> solve(int bucket_size, vector<query> qs){
        vector<Q> ret(qs.size());
        sort(begin(qs), end(qs), [&](query a, query b){
            int A = (a.l)/bucket_size, B = (b.l)/bucket_size;
            if(A != B) return A < B;
            if(A%2 == 0) return a.r < b.r;
            return a.r > b.r;
        });
        for(auto &e: qs){
            while(e.l < l) add_left(--l);
            while(r < e.r) add_right(r++);
            while(l < e.l) erase_left(l++);
            while(e.r < r) erase_right(--r);
            ret[e.id] = sp+(sq == 0? 1 : 0);
        }
        return ret;
    }
};

int main(){
    int N; cin >> N;

    vector<int> a(N);
    rep(i, N) {cin >> a[i]; a[i]--;}

    Mo<int, int> mo(a);

    int Q; cin >> Q;

    vector<query> qs;
    rep(i, Q){
        int l, r; cin >> l >> r; l--;
        qs.eb(l, r, i);
    }

    each(e, mo.solve(300, qs)){
        cout << e << '\n';
    }
}