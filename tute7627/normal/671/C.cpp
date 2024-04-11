//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>
void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>
void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
struct SegmentTreeBeats {
    static const long long INF = 1LL << 60;
    struct Node {
        Node *left, *right;
        long long max_v, smax_v, max_c;
        long long min_v, smin_v, min_c;
        long long sum;
        long long len, ladd, lval;

        Node() : left(0), right(0), ladd(0), lval(INF) {}

        void init(long long x) {
            max_v = min_v = sum = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = 1;
        }

        void init_empty() {
            max_v = smax_v = -INF;
            min_v = smin_v = INF;
            max_c = min_c = 0;
        }

        void update_max(long long x) {
            sum += (x - max_v) * max_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) max_v = smin_v = x;
            else                      max_v = x;
            if (lval != INF and x < lval) lval = x;
        }

        void update_min(long long x) {
            sum += (x - min_v) * min_c;
            /* */if (max_v ==  min_v) max_v =  min_v = x;
            else if (max_v == smin_v) min_v = smax_v = x;
            else                      min_v = x;
            if (lval != INF and lval < x) lval = x;
        }

        void addall(long long x) {
            max_v += x;
            if (smax_v != -INF) smax_v += x;
            min_v += x;
            if (smin_v != INF) smin_v += x;
            sum += len * x;
            if (lval != INF) lval += x;
            else             ladd += x;
        }

        void updateall(long long x) {
            max_v = min_v = x;
            smax_v = -INF; smin_v = INF;
            max_c = min_c = len;
            sum = len * x;
            lval = x; ladd = 0;
        }

        void push() {
            if (lval != INF) {
                 left -> updateall(lval);
                right -> updateall(lval);
                lval = INF;
                return;
            }
            if (ladd != 0) {
                 left -> addall(ladd);
                right -> addall(ladd);
                ladd = 0;
            }
            if (max_v < left -> max_v)   left -> update_max(max_v);
            if (left -> min_v < min_v)   left -> update_min(min_v);
            if (max_v < right -> max_v) right -> update_max(max_v);
            if (right -> min_v < min_v) right -> update_min(min_v);
        }

        void update() {
            sum = left -> sum + right -> sum;
            if (left -> max_v < right -> max_v) {
                max_v = right -> max_v;
                max_c = right -> max_c;
                smax_v = max(left -> max_v, right -> smax_v);
            } else if (left -> max_v > right -> max_v) {
                max_v = left -> max_v;
                max_c = left -> max_c;
                smax_v = max(left -> smax_v, right -> max_v);
            } else {
                max_v = left -> max_v;
                max_c = left -> max_c + right -> max_c;
                smax_v = max(left -> smax_v, right -> smax_v);
            }
            if (left -> min_v < right -> min_v) {
                min_v = left -> min_v;
                min_c = left -> min_c;
                smin_v = min(left -> smin_v, right -> min_v);
            } else if (left -> min_v > right -> min_v) {
                min_v = right -> min_v;
                min_c = right -> min_c;
                smin_v = min(left -> min_v, right -> smin_v);
            } else {
                min_v = left -> min_v;
                min_c = left -> min_c + right -> min_c;
                smin_v = min(left -> smin_v, right -> smin_v);
            }
        }
    };

    int n, n0;
    Node *root;

    void _update_min(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || nd -> max_v <= x) return;
        if (a <= l && r <= b && nd -> smax_v < x) {
            nd -> update_max(x);
            return;
        }
        nd -> push();
        _update_min(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_min(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_max(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a || x <= nd -> min_v) return;
        if (a <= l && r <= b && x < nd -> smin_v) {
            nd -> update_min(x);
            return;
        }
        nd -> push();
        _update_max(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_max(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _add_val(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> addall(x);
            return;
        }
        nd -> push();
        _add_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _add_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    void _update_val(long long x, int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return;
        if (a <= l && r <= b) {
            nd -> updateall(x);
            return;
        }
        nd -> push();
        _update_val(x, a, b, nd ->  left, l, (l + r) >> 1);
        _update_val(x, a, b, nd -> right, (l + r) >> 1, r);
        nd -> update();
    }

    long long _query_max(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return -INF;
        if (a <= l && r <= b) return nd -> max_v;
        nd -> push();
        long long lv = _query_max(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_max(a, b, nd -> right, (l + r) >> 1, r);
        return max(lv, rv);
    }

    long long _query_min(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return INF;
        if (a <= l && r <= b) return nd -> min_v;
        nd -> push();
        long long lv = _query_min(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_min(a, b, nd -> right, (l + r) >> 1, r);
        return min(lv, rv);
    }

    long long _query_sum(int a, int b, Node *nd, int l, int r) {
        if (b <= l || r <= a) return 0;
        if (a <= l && r <= b) return nd -> sum;
        nd -> push();
        long long lv = _query_sum(a, b, nd ->  left, l, (l + r) >> 1);
        long long rv = _query_sum(a, b, nd -> right, (l + r) >> 1, r);
        return lv + rv;
    }

    SegmentTreeBeats(int n, long long val = 0) : n(n) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(val);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }

    SegmentTreeBeats(vector<long long> a) : n(a.size()) {
        n0 = 1; while (n0 < n) n0 <<= 1;
        Node *nds = new Node[2 * n0];
        root = nds;
        nds[0].len = n0;
        for (int i = 0; i < n0 - 1; ++i) {
            nds[i].left = &nds[2 * i + 1];
            nds[i].right = &nds[2 * i + 2];
            nds[2 * i + 1].len = nds[2 * i + 2].len = nds[i].len >> 1;
        }
        for (int i = 0; i <  n; ++i) nds[n0 - 1 + i].init(a[i]);
        for (int i = n; i < n0; ++i) nds[n0 - 1 + i].init_empty();
        for (int i = n0 - 2; i >= 0; i--) nds[i].update();
    }

    void update_min(int a, int b, long long x) { _update_min(x, a, b, root, 0, n0); }
    void update_max(int a, int b, long long x) { _update_max(x, a, b, root, 0, n0); }
    void    add_val(int a, int b, long long x) {    _add_val(x, a, b, root, 0, n0); }
    void update_val(int a, int b, long long x) { _update_val(x, a, b, root, 0, n0); }
    long long query_max(int a, int b) { return _query_max(a, b, root, 0, n0); }
    long long query_min(int a, int b) { return _query_min(a, b, root, 0, n0); }
    long long query_sum(int a, int b) { return _query_sum(a, b, root, 0, n0); }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  ll sz=200005;
  vector<int>idx(sz,-1);
  rep(i,0,n)idx[a[i]]=i;
  vector<ll>b(n);
  rep(i,0,n)b[i]=i+1;
  SegmentTreeBeats seg(b);
  ll now=seg.query_sum(0,n);
  rrep(i,1,sz){
    int l1=n,l2=n,r1=-1,r2=-1;
    for(ll j=i;j<sz;j+=i){
      if(idx[j]!=-1){
        if(l1>idx[j]){
          l2=l1;
          l1=idx[j];
        }
        else if(l2>idx[j])l2=idx[j];
        if(r1<idx[j]){
          r2=r1;
          r1=idx[j];
        }
        else if(r2<idx[j])r2=idx[j];
      }
    }
    if(r2==-1)continue;
    seg.update_min(r1,n,l2+1);
    seg.update_min(r2,r1,l1+1);
    seg.update_min(0,r2,0);
    ll nxt=seg.query_sum(0,n);
    //cout<<i spa l1 spa l2 spa r1 spa r2 spa now spa nxt<<endl;
    res+=(now-nxt)*i;
    now=nxt;
  }
  cout<<res<<endl;
  return 0;
}