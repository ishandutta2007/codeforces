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

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

double EPS = 1e-8;

struct Segment{
    double h1, h2, x1, x2;
    Segment(double _h1, double _h2, double _x1, double _x2){
        h1 = _h1;
        h2 = _h2;
        x1 = _x1;
        x2 = _x2;
    }
};
void __print(Segment x) {cerr << '{' << x.h1 << ", " << x.h2 << ", " << x.x1 << ", " << x.x2 << '}';}

double intersection(double a1, double b1, double a2, double b2, double def = 0){
    if(abs(a1 - a2) + abs(b1 - b2) <= EPS) return def;
    debug(a1, b1, a2, b2, abs(a1 - a2) / (abs(a1 - a2) + abs(b1 - b2)));
    return abs(a1 - a2) / (abs(a1 - a2) + abs(b1 - b2));
}

double area(double h1, double h2, double w){
    return w * (h1 + h2) / 2.0;
}



double pt(double h1, double h2, double x){
    debug(h1, h2, x, h1 * (1-x) + h2 * x);
    return h1 * (1-x) + h2 * x;
}


double area(Segment s){
    return area(pt(s.h1, s.h2, s.x1), pt(s.h1, s.h2, s.x2), s.x2 - s.x1);
}

void solve_strip(int n, vd &ans, vector<pair<double, double>> heights){
    debug(n, ans, heights);
    vd total(n);
    vector<Segment> hull;
    hull.push_back(Segment(heights[0].first, heights[0].second, 0, 1));
    total[0] = area(hull[0]);
    debug(total[0]);
    for(int shape = 1; shape < n; shape++){
        debug(hull);
        int first, last;
        bool found = false;
        int m = hull.size();
        for(int i = 0; i < m; i++){
            if(pt(hull[i].h1, hull[i].h2, hull[i].x1) <= pt(heights[shape].first, heights[shape].second, hull[i].x1)){
                if(!found){
                    found = true;
                    first = i;
                }
                last = i;
            }
        }
        if(pt(hull[m-1].h1, hull[m-1].h2, hull[m-1].x2) <= pt(heights[shape].first, heights[shape].second, hull[m-1].x2)){
            if(!found){
                found = true;
                first = m;
            }
            last = m;
        }
        debug(shape, found, first, last);
        if(found){
            double start_x = (first == 0 ? 0 : intersection(heights[shape].first, heights[shape].second, hull[first-1].h1, hull[first-1].h2, hull[first-1].x1));
            double end_x = (last == m ? 1 : intersection(heights[shape].first, heights[shape].second, hull[last].h1, hull[last].h2, hull[last].x2));
            debug(start_x, end_x);
            
            if(start_x > 0){
                hull[first-1].x2 = start_x;
            }
            if(end_x < 1){
                hull[last].x1 = end_x;
            }
            vector<Segment> new_hull;
            for(int i = 0; i < first; i++){
                new_hull.push_back(hull[i]);
            }
            new_hull.push_back(Segment(heights[shape].first, heights[shape].second, start_x, end_x));
            for(int i = last; i < m; i++){
                new_hull.push_back(hull[i]);
            }
            hull = new_hull;
        }
        for(Segment s : hull){
            total[shape] += area(s);
        }
    }
    debug(total);
    ans[0] += total[0];
    for(int i = 1; i < n; i++){
        ans[i] += total[i] - total[i-1];
    }
}

void solve(){
    int n, k;
    cin >> n >> k;
    cout << setprecision(12);
    vvi pts(n, vi(k+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= k; j++){
            cin >> pts[i][j];
        }
    }
    vd ans(n);
    for(int i = 0; i < k; i++){
        debug(i);
        vector<pair<double, double>> heights;
        for(int j = 0; j < n; j++){
            heights.push_back({pts[j][i], pts[j][i+1]});
        }
        solve_strip(n, ans, heights);
    }
    for(int i = 0; i < n; i++){
        cout << ans[i] << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}