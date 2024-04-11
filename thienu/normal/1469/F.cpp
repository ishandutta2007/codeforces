#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

struct Node{
    ll val = 0, madd = 0;
    int lo, hi;
    Node *l, *r;
    Node(int lo, int hi) : lo(lo), hi(hi) {
        if(lo + 1 != hi){
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid);
            r = new Node(mid, hi);
            update();
        }
    }

    // first index that sum >= num, -1 otherwise
    int lower_bound(ll num, ll left = 0){
        // debug(lo, val);
        if(lo + 1 == hi){
            return lo;
        }
        push();
        if(val + left < num){
            return -1;
        }
        if(l->val + left >= num){
            return l->lower_bound(num, left);
        }
        return r->lower_bound(num, left + l->val);
    }

    void add(int L, int R, ll num){
        if(R <= lo || hi <= L) return;
        if(L <= lo && hi <= R){
            madd += num;
            val += num * (hi-lo);
            return;
        }
        push();
        l->add(L, R, num);
        r->add(L, R, num);
        update();
    }

    void update(){
        val = l->val + r->val;
    }

    void push(){
        if(madd != 0){
            l->add(lo, hi, madd);
            r->add(lo, hi, madd);
            madd = 0;
        }
    }
};

const int A = 4e5 + 5;

void solve(){
    int n; ll k;
    cin >> n >> k;
    vi len(n);
    for(int i = 0; i < n; i++) cin >> len[i];


    Node* st = new Node(0, A);

    st->add(0, 1, 1);

    sort(len.begin(), len.end(), greater<int>());
    int ans = 1e9;

    for(int i = 0; i < n; i++){
        // add strip, len[i]
        int idx = st->lower_bound(1);
        debug(idx);
        st->add(idx, idx+1, -1);
        int two = (len[i]-1)/2;
        st->add(idx+2, idx+2+two, 2);
        if(len[i] % 2 == 0){
            st->add(idx+2+two, idx+3+two, 1);
        }
        
        int lb = st->lower_bound(k);
        debug(lb);
        if(lb != -1){
            ans = min(ans, lb);
        }
    }
    debug(ans);
    if(ans == 1e9) ans = -1;
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}