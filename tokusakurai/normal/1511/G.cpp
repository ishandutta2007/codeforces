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

template<typename T>
struct Sqrt_Decomposition{
    struct Node{
        const int l, r;
        vector<T> v;
        vector<vector<T>> cnt;
        int s = 0, L = 0;

        Node(const vector<T> &a, int l, int r) : l(l), r(r) {
            v.resize(r-l);
            copy(begin(a)+l, begin(a)+r, begin(v));
            rep2(i, l, r-1) s ^= a[i]*i;

            rep2(i, l, r-1){
                cnt.eb(vector<T>(20, a[i]));
            }

            rep3(i, r-1, l){
                rep(j, 20){
                    if(i+(1<<j) < r) cnt[i-l][j] ^= cnt[i+(1<<j)-l][j];
                }
            }
        }

        void query1(int a, int b){
            chmax(a, l), chmin(b, r);
            if(a == l && b == r) query1_all();
            L++;
        }

        void query1_all(){
            rep(i, 19){
                int m = (1<<i)+(1<<18)-(l-L);
                m &= (1<<(i+1))-1;

                T x = (l+m < r? cnt[m][i+1] : 0);
                if(x) s ^= (1<<(i+1))-1;
            }
        }

        T query2(int a, int b){
            chmax(a, l), chmin(b, r);
            if(a >= b) return 0;
            if(a == l && b == r) {return query2_all();}

            T ret = 0;
            rep2(i, a, b-1) ret ^= v[i-l]*(i-L);
            return ret;
        }

        T query2_all(){
            return s;
        }
    };

    vector<Node> nodes;

    Sqrt_Decomposition(const vector<T> &a, int bucket_size){
        for(int i = 0; i < sz(a); i += bucket_size){
            nodes.eb(a, i, min(i+bucket_size, sz(a)));
        }
    }

    void query1(int a, int b) {each(e, nodes) e.query1(a, b);}

    T query2(int a, int b){
        T ret = 0;
        each(e, nodes) ret ^= e.query2(a, b);
        return ret;
    }
};

int main(){
    int N, M; cin >> N >> M;

    vector<int> a(M, 0);
    rep(i, N){
        int c; cin >> c; c--;
        a[c] ^= 1;
    }

    int Q; cin >> Q;
    
    vector<vector<pii>> qs(M);

    rep(i, Q){
        int L, R; cin >> L >> R; L--;
        qs[L].eb(R, i);
    }

    Sqrt_Decomposition seg(a, 2000);
    
    vector<int> ans(Q);

    rep(i, M){
        each(e, qs[i]){
            ans[e.second] = seg.query2(i, e.first);
        }

        seg.query1(i+1, M);
    }

    //each(e, ans) cout << e << ' '; cout << '\n';

    each(e, ans){
        cout << (e == 0? 'B' : 'A');
    }
    cout << '\n';
}