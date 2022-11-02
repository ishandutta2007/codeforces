//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef pair<int, int> pii;

struct pt{
    int x, y;
    pt(){}
    pt(int _x, int _y):x(_x), y(_y){}
    pt operator + (const pt & p)const{
        return pt(x + p.x, y + p.y);
    }
    pt operator - (const pt & p)const{
        return pt(x - p.x, y - p.y);
    }
    int cross(const pt & p)const{
        return x * p.y - y * p.x;
    }
    int cross(const pt & p, const pt & q)const{
        return (p - *this).cross(q - *this);
    }
    int dot(const pt & p)const{
        return x * p.x + y * p.y;
    }
    int dot(const pt & p, const pt & q)const{
        return (p - *this).dot(q - *this);
    }
};

vector<pt> graham(vector<pt> p){
    int n = p.size();
    int pos = 0;
    for(int i = 1; i < n; i++){
        if(p[i].x < p[pos].x || (p[i].x == p[pos].x && p[i].y < p[pos].y))
            pos = i;
    }
    swap(p[0], p[pos]);
    pt base = p[0];
    sort(1 + all(p), [&base](const pt & l, const pt & r){return base.cross(l, r) == 0 ? base.dot(l, l) < base.dot(r, r) : base.cross(l, r) > 0;});
    int ptr = n - 1;
    while(ptr > 0 && base.cross(p[ptr], p[n - 1]) == 0)
        --ptr;
    //reverse(ptr + 1 + all(p));
    vector<pt> stk;
    for(int i = 0; i < n; i++){
        while(stk.size() >= 2u && stk[stk.size() - 2].cross(stk.back(), p[i]) <= 0)
            stk.pop_back();
        stk.push_back(p[i]);
    }
    return stk;
}

void solve(){
    int n;
    cin >> n;
    if(!n)
        exit(0);
    vector<string> s(n);
    vector<pt> cand;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    auto isZero = [&n, &s](int i, int j){
        if(i < 0 || j < 0 || i >= n || j >= n)
            return true;
        else return s[i][j] == '0';
    };
    vector<int> ds = {-1, 1};
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(isZero(i, j))
                continue;
            for(int dx: ds){
                for(int dy: ds){
                    if(isZero(i - dx, j - dy) && isZero(i - dx, j) && isZero(i, j - dy) && !isZero(i + dx, j + dy)){
                        //cerr << "cell " << i << ' ' << j << " gives " << i + max(0, dx) << ' ' << j + max(0, dy) << endl;
                        cand.emplace_back(i + max(0, dx), j + max(0, dy));
                    }
                }
            }
        }
    }
    auto hull = graham(cand);
    for(pt& p: hull){
        int x = p.y;
        int y = n - p.x;
        p = pt(x, y);
    }
    reverse(all(hull));
    size_t pos = 0;
    for(size_t i = 1; i < hull.size(); i++)
        if(hull[i].x < hull[pos].x || (hull[i].x == hull[pos].x && hull[i].y < hull[pos].y))
            pos = i;
    rotate(hull.begin(), hull.begin() + pos, hull.end());
    cout << hull.size() << '\n';
    for(auto p: hull){
        cout << p.x << ' ' << p.y << '\n';
    }
}

signed main(){
//    freopen("areas.in", "r", stdin);
//    freopen("areas.out", "w", stdout);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T=1;
    //cin >> T;
    while(1)
        solve();
    return 0;
}