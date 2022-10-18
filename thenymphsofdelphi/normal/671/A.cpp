#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (auto i = (l); i < (r); i++)
#define ForE(i, l, r) for (auto i = (l); i <= (r); i++)
#define FordE(i, l, r) for (auto i = (l); i >= (r); i--)
#define Fora(v, a) for (auto v: (a))
#define bend(a) (a).begin(), (a).end()
#define isz(a) ((signed)(a).size())

using ll = long long;
using ld = long double;
using pii = pair <int, int>;
using vi = vector <int>;
using vpii = vector <pii>;
using vvi = vector <vi>;

template<class T>
struct point{
    T x{}, y{};
    point(){ }
    template<class U> point(const point<U> &otr): x(otr.x), y(otr.y){ }
    template<class U, class V> point(U x, V y): x(x), y(y){ }
    template<class U> explicit operator point<U>() const{
        return point<U>(static_cast<U>(x), static_cast<U>(y));
    }
    T operator*(const point &otr) const{
        return x * otr.x + y * otr.y;
    }
    T operator^(const point &otr) const{
        return x * otr.y - y * otr.x;
    }
    point operator+(const point &otr) const{
        return {x + otr.x, y + otr.y};
    }
    point &operator+=(const point &otr){
        return *this = *this + otr;
    }
    point operator-(const point &otr) const{
        return {x - otr.x, y - otr.y};
    }
    point &operator-=(const point &otr){
        return *this = *this - otr;
    }
    point operator-() const{
        return {-x, -y};
    }
#define scalarop_l(op) friend point operator op(const T &c, const point &p){ return {c op p.x, c op p.y}; }
    scalarop_l(+) scalarop_l(-) scalarop_l(*) scalarop_l(/)
#define scalarop_r(op) point operator op(const T &c) const{ return {x op c, y op c}; }
    scalarop_r(+) scalarop_r(-) scalarop_r(*) scalarop_r(/)
#define scalarapply(op) point &operator op(const T &c){ return *this = *this op c; }
    scalarapply(+=) scalarapply(-=) scalarapply(*=) scalarapply(/=)
#define compareop(op) bool operator op(const point &otr) const{ return pair(x, y) op pair(otr.x, otr.y); }
    compareop(>) compareop(<) compareop(>=) compareop(<=) compareop(==) compareop(!=)
#undef scalarop_l
#undef scalarop_r
#undef scalarapply
#undef compareop
    double norm() const{
        return sqrt(x * x + y * y);
    }
    T squared_norm() const{
        return x * x + y * y;
    }
    double angle() const{
        return atan2(y, x);
    } // [-pi, pi]
    point<double> unit() const{
        return point<double>(x, y) / norm();
    }
    point perp() const{
        return {-y, x};
    }
    point<double> normal() const{
        return perp().unit();
    }
    point<double> rotate(const double &theta) const{
        return {x * cos(theta) - y * sin(theta), x * sin(theta) + y * cos(theta)};
    }
    point reflect_x() const{
        return {x, -y};
    }
    point reflect_y() const{
        return {-x, y};
    }
    point reflect(const point &o = {}) const{
        return {2 * o.x - x, 2 * o.y - y};
    }
    bool operator||(const point &otr) const{
        return !(*this ^ otr);
    }
};
template<class T> istream &operator>>(istream &in, point<T> &p){
    return in >> p.x >> p.y;
}
template<class T> ostream &operator<<(ostream &out, const point<T> &p){
    return out << "{" << p.x << ", " << p.y << "}";
}
template<class T>
double distance(const point<T> &p, const point<T> &q){
    return (p - q).norm();
}
template<class T>
T squared_distance(const point<T> &p, const point<T> &q){
    return (p - q).squared_norm();
}
template<class T, class U, class V>
T doubled_signed_area(const point<T> &p, const point<U> &q, const point<V> &r){
    return q - p ^ r - p;
}
template<class T>
T doubled_signed_area(const vector<point<T>> &a){
    if(a.empty()){
        return 0;
    }
    int n = (int)a.size();
    T res = a.back() ^ a.front();
    for(auto i = 1; i < n; ++ i) res += a[i - 1] ^ a[i];
    return res;
}
template<class T>
double angle(const point<T> &p, const point<T> &q){
    return atan2(p ^ q, p * q);
}
template<class T>
bool is_sorted(const point<T> &origin, point<T> p, point<T> q, point<T> r){
    p -= origin, q -= origin, r -= origin;
    T x = p ^ r, y = p ^ q, z = q ^ r;
    return x >= 0 && y >= 0 && z >= 0 || x < 0 && (y >= 0 || z >= 0);
} // check if p->q->r is sorted with respect to the origin
template<class T, class IT>
bool is_sorted(const point<T> &origin, IT begin, IT end){
    for(auto i = 0; i < (int)(end - begin) - 2; ++ i) if(!is_sorted(origin, *(begin + i), *(begin + i + 1), *(begin + i + 2))) return false;
    return true;
} // check if begin->end is sorted with respect to the origin
template<class T>
bool counterclockwise(const point<T> &p, const point<T> &q, const point<T> &r){
    return doubled_signed_area(p, q, r) > 0;
}
template<class T>
bool clockwise(const point<T> &p, const point<T> &q, const point<T> &r){
    return doubled_signed_area(p, q, r) < 0;
}

using pointint = point<int>;
using pointll = point<long long>;
using pointlll = point<__int128_t>;
using pointd = point<double>;
using pointld = point<long double>;

const int N = 1e5 + 5;

pointll b, c, d;
int n;
pointll a[N];

ld sum, ans = 1e18;
pair <double, int> distb[N], distc[N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("KEK.inp", "r", stdin);
    // freopen("KEK.out", "w", stdout);
    cin >> b >> c >> d;
    cin >> n;
    ForE(i, 1, n){
        cin >> a[i];
    }

    ForE(i, 1, n){
        sum += distance(d, a[i]) * 2;
    }

    ForE(i, 1, n){
        distb[i] = make_pair(distance(b, a[i]) - distance(a[i], d), i);
        distc[i] = make_pair(distance(c, a[i]) - distance(a[i], d), i);
    }
    sort(distb + 1, distb + n + 1);
    sort(distc + 1, distc + n + 1);

    ans = min(ans, sum + distb[1].fi);
    ans = min(ans, sum + distc[1].fi);
    if (n >= 1 and distb[1].se != distc[1].se){
        ans = min(ans, sum + distb[1].fi + distc[1].fi);
    }
    if (n >= 2 and distb[1].se != distc[2].se){
        ans = min(ans, sum + distb[1].fi + distc[2].fi);
    }
    if (n >= 2 and distb[2].se != distc[1].se){
        ans = min(ans, sum + distb[2].fi + distc[1].fi);
    }
    cout << fixed << setprecision(12) << ans << endl;
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/