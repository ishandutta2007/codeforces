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

const int INF = 1e9 + 7;

const long double PI = (long double) 4 * atan((long double) 1);

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
    typedef Point P;
    T x, y;
    int idx;
    explicit Point(T x=0, T y=0, int idx=0) : x(x), y(y), idx(idx) {}
    bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
    bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
    P operator+(P p) const { return P(x+p.x, y+p.y); }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x*d, y*d); }
    P operator/(T d) const { return P(x/d, y/d); }
    T dot(P p) const { return x*p.x + y*p.y; }
    T cross(P p) const { return x*p.y - y*p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x*x + y*y; }
    long double dist() const { return sqrt((long double)dist2()); }
    // angle to x-axis in interval [-pi, pi]
    long double angle() const { return atan2((long double) y, (long double) x); }
    long double angle(P p) const {
        long double alpha = p.angle() - angle();
        if(alpha > PI) alpha -= 2*PI;
        if(alpha < -PI) alpha += 2*PI;
        return alpha;
    }
    P unit() const { return *this/dist(); } // makes dist()=1
    P perp() const { return P(-y, x); } // rotates +90 degrees
    P normal() const { return perp().unit(); }
    // returns point rotated 'a' radians ccw around the origin
    P rotate(double a) const {
        return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")"; }
};
using P = Point<ll>;

void solve(){
    int n;
    cin >> n;
    vector<P> pts;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        pts.push_back(P(x, y, i));
    }
    debug(pts);
    vi turn_left;
    string s;
    cin >> s;
    for(char &c : s){
        turn_left.push_back(c == 'L');
    }
    debug(turn_left);
    
    vi ans;
    vi used(n);
    P cur = P(INF, INF);
    for(P p : pts){
        if(p.y < cur.y){
            cur = p;
        }
    }
    debug(cur);
    used[cur.idx] = 1;
    ans.push_back(cur.idx);
    P vec = P(1, 0);
    for(int i = 0; i < n-2; i++){
        int nxt_left = turn_left[i];
        long double best_angle = -1e10;
        P best;
        for(P p : pts){
            if(used[p.idx]) continue;
            // long double ang = (long double) (vec.cross(p-cur)) / (vec.dist() * (p-cur).dist());
            long double ang = vec.angle(p-cur);
            if(nxt_left) ang = -ang;
            if(ang > best_angle){
                best_angle = ang;
                best = p;
            }
        }
        debug(best, best.idx, best_angle);
        vec = best-cur;
        cur = best;
        used[cur.idx] = 1;
        ans.push_back(cur.idx);
    }
    for(int i = 0; i < n; i++){
        if(!used[i]){
            ans.push_back(i);
            break;
        }
    }
    for(int i : ans){
        cout << i+1 << ' ';
    }
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}