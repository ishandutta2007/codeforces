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
    ll x, y;
    pt(){}
    pt(ll _x, ll _y):x(_x), y(_y){}
    pt operator + (const pt & p)const{
        return pt(x + p.x, y + p.y);
    }
    pt operator - (const pt & p)const{
        return pt(x - p.x, y - p.y);
    }
    ll cross(const pt & p)const{
        return x * p.y - y * p.x;
    }
    ll cross(const pt & p, const pt & q)const{
        return (p - *this).cross(q - *this);
    }
    bool operator < (const pt & p)const{
        return x < p.x || (x == p.x && y < p.y);
    }
};

int sgn(ll x){
    return x < 0 ? -1 : int(x > 0);
}

const int N = (int)1e5 + 5;

int n;
pt p[N];
pt hull[N];
int sz = 0;

void graham(){
    sort(p, p + n);
    vector<pt> up, down;
    up.push_back(p[0]);
    down.push_back(p[0]);
    for(int i = 1; i < n; i++){
        if(i == n - 1 || p[0].cross(p[i], p[n - 1]) < 0){
            while(up.size() >= 2u && up[up.size() - 2u].cross(up.back(), p[i]) >= 0)
                up.pop_back();
            up.push_back(p[i]);
        }
        if(i == n - 1 || p[0].cross(p[i], p[n - 1]) > 0){
            while(down.size() >= 2u && down[down.size() - 2u].cross(down.back(), p[i]) <= 0)
                down.pop_back();
            down.push_back(p[i]);
        }
    }
    copy(all(up), hull);
    sz = up.size();
    for(int i = (int)down.size() - 2; i >= 0; i--)
        hull[sz++] = down[i];
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> p[i].x >> p[i].y;
        p[i].y -= p[i].x * p[i].x;
    }
    graham();
    if(sz <= 2)
        cout << sz - 1 << endl;
    else{
        int ans = 0;
        for(int i = 0; i < sz; i++){
            int j = i == sz - 1 ? 0 : (i + 1);
            int k = j == sz - 1 ? 0 : (j + 1);
            if(hull[i].x != hull[j].x && hull[i].cross(hull[j], hull[k]) != 0){
                pt up = hull[i] + pt(0, 1);
                if(sgn(hull[i].cross(hull[j], up)) != sgn(hull[i].cross(hull[j], hull[k])))
                    ++ans;
            }
        }
        cout << ans << endl;
    }
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while(T--)
        solve();
    return 0;
}