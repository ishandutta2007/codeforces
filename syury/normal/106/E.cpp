//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define move fjgjgjgjghd

typedef long long ll;
typedef double dbl;
typedef pair<int, int> pii;

const int STEPS = 80;
const int N = 111;
const dbl BND = 1e4 + 20;
const dbl phi = (1 + sqrt(5.0))/2;

int x[N], y[N], z[N];
int n;

dbl sqr(dbl x){ret x * x;}

dbl f(dbl cx, dbl cy, dbl cz){
    dbl result = 0;
    F(i, 0, n)
        result = max(result, sqrt(sqr(cx - x[i]) + sqr(cy - y[i]) + sqr(cz - z[i])));
    ret result;
}

dbl find_z(dbl x, dbl y){
    dbl l = -BND, r = BND;
    dbl f1, f2;
    dbl m1, m2;
    F(i, 0, STEPS){
        if(!i){
            m1 = l + (r - l)/(phi + 1), m2 = r - (r - l)/(phi + 1);
            f1 = f(x, y, m1);
            f2 = f(x, y, m2);
        }
        if(f1 < f2){
            r = m2;
            m2 = m1;
            f2 = f1;
            if(i + 1 == STEPS)brk;
            m1 = l + (r - l)/(phi + 1);
            f1 = f(x, y, m1);
        }
        else{
            l = m1;
            m1 = m2;
            f1 = f2;
            if(i + 1 == STEPS)brk;
            m2 = r - (r - l)/(phi + 1);
            f2 = f(x, y, m2);
        }
    }
    ret (l + r)/2;
}

pair <dbl, dbl> find_y(dbl x){
    dbl l = -BND, r = BND;
    dbl f1, f2;
    dbl m1, m2;
    dbl zl;
    dbl zr;
    F(i, 0, STEPS){
        if(!i){
            m1 = l + (r - l)/(phi + 1), m2 = r - (r - l)/(phi + 1);
            zl = find_z(x, m1); f1 = f(x, m1, zl);
            zr = find_z(x, m2); f2 = f(x, m2, zr);
        }
        if(f1 < f2){
            r = m2;
            m2 = m1;
            f2 = f1;
            zr = zl;
            if(i + 1 == STEPS)brk;
            m1 = l + (r - l)/(phi + 1);
            zl = find_z(x, m1); f1 = f(x, m1, zl);
        }
        else{
            l = m1;
            m1 = m2;
            f1 = f2;
            zl = zr;
            if(i + 1 == STEPS)brk;
            m2 = r - (r - l)/(phi + 1);
            zr = find_z(x, m2); f2 = f(x, m2, zr);
        }
    }
    dbl kek = (l + r)/2;
    zr = find_z(x, kek);
    ret {kek, zr};
}
tuple<dbl, dbl, dbl> find_x(){
    dbl l = -BND, r = BND;
    dbl f1, f2;
    dbl m1, m2;
    dbl yl, zl;
    dbl yr, zr;
    F(i, 0, STEPS){
        if(!i){
            m1 = l + (r - l)/(phi + 1), m2 = r - (r - l)/(phi + 1);
            tie(yl, zl) = find_y(m1); f1 = f(m1, yl, zl);
            tie(yr, zr) = find_y(m2); f2 = f(m2, yr, zr);
        }
        if(f1 < f2){
            r = m2;
            m2 = m1;
            f2 = f1;
            yr = yl; zr = zl;
            if(i + 1 == STEPS)brk;
            m1 = l + (r - l)/(phi + 1);
            tie(yl, zl) = find_y(m1); f1 = f(m1, yl, zl);
        }
        else{
            l = m1;
            m1 = m2;
            f1 = f2;
            yl = yr; zl = zr;
            if(i + 1 == STEPS)brk;
            m2 = r - (r - l)/(phi + 1);
            tie(yr, zr) = find_y(m2); f2 = f(m2, yr, zr);
        }
    }
    dbl kek = (l + r)/2;
    tie(yl, zr) = find_y(kek);
    ret {kek, yl, zr};
}

int main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    F(i, 0, n)
        cin >> x[i] >> y[i] >> z[i];
    dbl ax, ay, az;
    tie(ax, ay, az) = find_x();
    cout.precision(16);
    cout << fixed << ax << ' ' << ay << ' ' << az << endl;
    return 0;
}