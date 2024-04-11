#include <bits/stdc++.h>

using namespace std;

#define sz(x) (int) x.size()
#define PI acosl(-1)

class cmpl {
    public:
        double real, imag;
        cmpl operator+(const cmpl& o) {
            cmpl ret;
            ret.real = this->real + o.real;
            ret.imag = this->imag + o.imag;
            return ret;
        }
        cmpl operator*(const cmpl& o) {
            cmpl ret;
            ret.real = this->real * o.real - this->imag * o.imag;
            ret.imag = this->real * o.imag + this->imag * o.real;
            return ret;
        }
        cmpl operator-(const cmpl& o) {
            cmpl ret;
            ret.real = this->real - o.real;
            ret.imag = this->imag - o.imag;
            return ret;
        }
        double norm() {
            return sqrt(this->real * this->real + this->imag * this->imag);
        }
};

struct modify {
    int theta;
    cmpl translate;
};

double cs[361], sn[361];

cmpl cis(int theta) {
    theta %= 360;
    if(theta < 0) theta += 360;
    return {cs[theta], sn[theta]};
}

void ch(modify &x, modify y) {
    x.theta += y.theta;
    x.translate = x.translate * cis(y.theta);
    x.translate = x.translate + y.translate;
}

cmpl get_new(cmpl a, modify x) {
    return a * cis(x.theta) + x.translate;
}

cmpl to_translate(cmpl a, cmpl b, int z) {
    double len = (a - b).norm();
    double diffX = b.real - a.real;
    double diffY = b.imag - a.imag;
    return {diffX / len * 1.0 * z, diffY / len * 1.0 * z};
}

struct seg_tree {
    vector<modify> seg;
    vector<modify> lazy;
    int sz;
    void init(int n) {
        sz = 1;
        while(sz < n) sz *= 2;
        seg.resize(2 * sz);
        lazy.resize(2 * sz);
    }
    void push(int x, int lx, int rx, modify v) {
        ch(seg[x], v);
        if(rx - lx != 1) {
            ch(lazy[2 * x + 1], v);
            ch(lazy[2 * x + 2], v);
        }
    }
    void prop(int x, int lx, int rx) {
        push(x, lx, rx, lazy[x]);
        lazy[x] = {0, 0};
    }

    void upd(int l, int r, modify v, int x, int lx, int rx) {
        prop(x, lx, rx);
        if(lx >= r || rx <= l) return;
        if(lx >= l && rx <= r) {
            push(x, lx, rx, v);
            return;
        }
        int m = (lx + rx) / 2;
        upd(l, r, v, 2 * x + 1, lx, m);
        upd(l, r, v, 2 * x + 2, m, rx);
    }
    void upd(int l, int r, modify v) { upd(l, r, v, 0, 0, sz); }
    modify query(int i, int x, int lx, int rx) {
        prop(x, lx, rx);
        if(rx - lx == 1) {
            return seg[x];
        }
        int m = (lx + rx) / 2;
        if(i < m) return query(i, 2 * x + 1, lx, m);
        else return query(i, 2 * x + 2, m, rx);
    }
    modify query(int i) { return query(i, 0, 0, sz); }
    cmpl get_pos(int i) {
        modify m = query(i);
        return get_new({i * 1.0, 0}, m);
    }
} in;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 0; i <= 360; i++) {
        cs[i] = cos(i * PI / 180.0);
        sn[i] = sin(i * PI / 180.0);
    }

    int n, m; cin >> n >> m;
    in.init(n + 1);
    vector<pair<double, double>> ret(m);
    
    cout << setprecision(24);
    for(int i = 0; i < m; i++) {
        int type; cin >> type;
        int y, z; cin >> y >> z;
        if(type == 2) {
            int theta = -z;
            cmpl lst = in.get_pos(y - 1);
            modify m = {theta, lst - lst * cis(theta)};
            in.upd(y, n + 1, m);
        }
        else {
            cmpl a = in.get_pos(y - 1), b = in.get_pos(y);
            cmpl trans = to_translate(a, b, z);
            modify m = {0, trans};
            in.upd(y, n + 1, m);
        }
        cmpl ans = in.get_pos(n);
        ret[i] = {ans.real, ans.imag};
    }

    for(auto &it : ret) {
        cout << it.first << " " << it.second << "\n";
    }
}