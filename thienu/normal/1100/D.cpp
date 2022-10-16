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

struct Point{
    int x, y;
    Point(int x, int y) : x(x), y(y){}
};

void make_move(int xd, int yd, Point &king, vector<Point> &rooks){
    king.x += xd;
    king.y += yd;
    cout << king.x << ' ' << king.y << endl;
    int k, x, y;
    cin >> k >> x >> y;
    if(k == -1 && x == -1 && y == -1) exit(0);
    if(k == 0 && x == 0 && y == 0) exit(0);
    k--;
    rooks[k].x = x;
    rooks[k].y = y;
}

bool can_move(int xd, int yd, Point &king, vector<Point> &rooks){
    for(Point p : rooks){
        if(p.x == king.x + xd && p.y == king.y + yd) return false;
    }
    return true;
}

void solve(){
    int n = 666;
    int x, y;
    cin >> x >> y;
    Point king = Point(x, y);
    vector<Point> rooks;
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        rooks.push_back(Point(x, y));
    }
    while(king.x < 500) make_move(1, 0, king, rooks);
    while(king.x > 500) make_move(-1, 0, king, rooks);
    while(king.y < 500) make_move(0, 1, king, rooks);
    while(king.y > 500) make_move(0, -1, king, rooks);
    
    vi quad(4);
    for(int i = 0; i < n; i++){
        int q = (rooks[i].x < 500) + (rooks[i].y < 500) * 2;
        quad[q]++;
    }
    int mq = min_element(quad.begin(), quad.end()) - quad.begin();
    int dx = (mq == 0 || mq == 2) ? -1 : 1;
    int dy = (mq == 0 || mq == 1) ? -1 : 1;
    while(true){
        if(can_move(dx, dy, king, rooks)){
            make_move(dx, dy, king, rooks);
        }else{
            make_move(dx, 0, king, rooks);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}