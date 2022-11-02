#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

using dbl = long double;
using vec2 = pair<dbl, dbl>;

struct Mat {
    dbl a, b, c, d, e, f;

    static Mat ident() {
        return {1, 0, 0, 0, 1, 0};
    }

    Mat operator*(const Mat& r) const {
        dbl g = r.a, h = r.b, i = r.c;
        dbl j = r.d, k = r.e, l = r.f;
        return { a*g+b*j, a*h+b*k, a*i+b*l+c, d*g+e*j, d*h+e*k, d*i+e*l+f };
    }

    vec2 origin() const {
        return {c, f};
    }
};

vector<Mat> tree;
int len;

void mul(int vb, int ve, Mat mat, int i = 1, int b = 0, int e = len) {
    if (b >= ve || vb >= e) return;
    
    if (b >= vb && e <= ve) {
        tree[i] = mat*tree[i];
        return;
    }

    int m = (b+e) / 2;

    tree[i*2] = tree[i]*tree[i*2];
    tree[i*2+1] = tree[i]*tree[i*2+1];
    tree[i] = Mat::ident();

    mul(vb, ve, mat, i*2, b, m);
    mul(vb, ve, mat, i*2+1, m, e);
}

vec2 get(int i) {
    Mat mat = tree[i += len];
    while (i /= 2) {
        mat = tree[i]*mat;
    }
    return mat.origin();
}

void run() {
    int n, m; cin >> n >> m;
    cout << setprecision(10);

    for (len = 1; len < n+1; len *= 2);
    tree.resize(len*2, Mat::ident());

    rep(i, 0, n+1) {
        tree[i+len].c = i;
    }

    rep(i, 0, m) {
        int x, y, z; cin >> x >> y >> z;

        if (x == 1) {
            vec2 a = get(y-1), b = get(y);
            dbl tx = b.x-a.x, ty = b.y-a.y;
            dbl scale = sqrtl(tx*tx + ty*ty);
            tx /= scale;
            ty /= scale;
            mul(y, n+1, {1, 0, tx*z, 0, 1, ty*z});
        } else {
            vec2 a = get(y-1);
            dbl ang = dbl(-z) / 180 * M_PI;
            Mat mat = {1, 0, -a.x, 0, 1, -a.y};
            mat = Mat{cosl(ang), -sinl(ang), a.x, sinl(ang), cosl(ang), a.y} * mat;
            mul(y, n+1, mat);
        }

        vec2 v = get(n);
        cout << v.x << ' ' << v.y << '\n';
    }
}