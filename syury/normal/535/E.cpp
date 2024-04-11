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

struct Frac{
    __int128 p, q;
    Frac():p(0), q(1){}
    Frac(__int128 _x, __int128 _y):p(_x), q(_y){}
    Frac operator + (const Frac & f)const{
        return Frac(p * f.q + q * f.p, q * f.q);
    }
    Frac operator - (const Frac & f)const{
        return Frac(p * f.q - q * f.p, q * f.q);
    }
    Frac operator * (const Frac & f)const{
        return Frac(p * f.p, q * f.q);
    }
    Frac operator / (const Frac & f)const{
        return f.p < 0 ? Frac(-p * f.q, -q * f.p) : Frac(p * f.q, q * f.p);
    }
    bool operator < (const Frac & f)const{
        auto diff = *this - f;
        return diff.p < 0;
    }
    bool operator > (const Frac & f)const{
        auto diff = *this - f;
        return diff.p > 0;
    }
    bool operator == (const Frac & f)const{
        auto diff = *this - f;
        return diff.p == 0;
    }
    bool operator != (const Frac & f)const{
        auto diff = *this - f;
        return diff.p != 0;
    }
};

struct pt{
    Frac x, y;
    int id;
    pt(){}
    pt(Frac _x, Frac _y):x(_x), y(_y){}
    pt operator + (const pt & p)const{
        return pt(x + p.x, y + p.y);
    }
    pt operator - (const pt & p)const{
        return pt(x - p.x, y - p.y);
    }
    Frac cross(const pt & p)const{
        return x * p.y - y * p.x;
    }
    Frac cross(const pt & p, const pt & q)const{
        return (p - *this).cross(q - *this);
    }
    Frac dot(const pt & p)const{
        return x * p.x + y * p.y;
    }
    Frac dot(const pt & p, const pt & q)const{
        return (p - *this).cross(q - *this);
    }
};

vector<int> hull(vector<pt> p){
    int pos = 0;
    for(int i = 1; i < (int)p.size(); i++){
        if(p[i].x < p[pos].x || (p[i].x == p[pos].x && p[i].y < p[pos].y))
            pos = i;
    }
    swap(p[0], p[pos]);
    auto base = p[0];
    sort(p.begin() + 1, p.end(), [&base](const pt & l, const pt & r){
            return base.cross(l, r) == Frac(0, 1) ? l.dot(base, r) < Frac(0, 1) : base.cross(l, r) > Frac(0, 1);
            });
    int ptr = p.size() - 2;
    while(ptr > 0 && p[0].cross(p[ptr], p.back()) == Frac(0, 1))
        --ptr;
    reverse(p.begin() + ptr + 1, p.end());
    vector<int> stk(p.size());
    stk[0] = 0;
    int sz = 1;
    for(int i = 1; i < (int)p.size(); i++){
        while(sz > 1 && p[stk[sz - 2]].cross(p[i], p[stk[sz - 1]]) > Frac(0, 1))
            --sz;
        stk[sz++] = i;
    }
    stk.resize(sz);
    for(int& x: stk)
        x = p[x].id;
    return stk;
}

void solve(){
    vector<pt> p;
    int n;
    cin >> n;
    vector<pii> lol(n);
    map<pii, int> avtor_pidoras;
    vector<vector<int> > zadacha_govno(n);
    for(int i = 0; i < n; i++){
        int r, s;
        cin >> r >> s;
        lol[i] = {r, s};
        if(!avtor_pidoras.count(lol[i])){
            avtor_pidoras[lol[i]] = i;
        }
        zadacha_govno[avtor_pidoras[lol[i]]].push_back(i);
    }
    vector<int> avtor_cyka;
    for(int i = 0; i < n; i++){
        if(avtor_pidoras[lol[i]] != i)
            continue;
        pt curr(Frac(1, lol[i].X), Frac(1, lol[i].Y));
        avtor_cyka.push_back(i);
        curr.id = p.size();
        p.push_back(curr);
    }
    n = p.size();
    auto h = hull(p);
    bool avtor_gnida = 0;
    if(h.size() > 2u){
        bool govno_zhopa = 0;
        for(int i = 2; i < h.size(); i++)
            if(!(p[h[0]].cross(p[h[1]], p[h[i]]) == Frac(0, 1)))
                govno_zhopa = 1;
        if(govno_zhopa == 0){
            if(p[h[0]].x != p[h[1]].x && p[h[0]].y != p[h[1]].y){
                avtor_gnida = 1;
            }
        }
    }
    vector<int> ans;
    size_t up = 0, right = 0;
    for(size_t i = 1; i < h.size(); i++){
        if(p[h[i]].y < p[h[up]].y || (p[h[i]].y == p[h[up]].y && p[h[i]].x < p[h[up]].x))
            up = i;
        if(p[h[i]].x < p[h[right]].x || (p[h[i]].x == p[h[right]].x && p[h[i]].y < p[h[right]].y))
            right = i;
    }
    for(size_t i = right; i != up; i = (i + 1)%h.size())
        for(int ziga: zadacha_govno[avtor_cyka[h[i]]])
            ans.push_back(ziga);
    for(int ziga: zadacha_govno[avtor_cyka[h[up]]])
        ans.push_back(ziga);
    if(avtor_gnida && up != right){
        ans.resize(lol.size());
        iota(all(ans), 0);
    }
    sort(all(ans));
    for(int x: ans)cout << 1 + x << ' ';
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