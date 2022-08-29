// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;

using P = pair<int, int>;
const int M = 1000000007;

using itype = int;
using fltype = long double;


struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};



template<typename T>
struct Point {
    int id;
    T x, y, z;
    Point() {}
    Point(T x, T y, T z) : id(-1), x(x), y(y), z(z) {}
    Point(int id, T x, T y, T z) : id(id), x(x), y(y), z(z) {}
};

using Vector = Point<fltype>;

fltype sq(fltype x) {
    return x * x;
}

// fltype calc_dist(const Point<fltype>& p1, const Point<fltype>& p2) {
//     return sqrt(sq(p1.x - p2.x) + sq(p1.y - p2.y) + sq(p1.z - p2.z));
// }

fltype calc_area(const Vector& v1, const Vector& v2) {
    return 0.5 * sqrt(sq(v1.x * v2.y - v1.y * v2.x) + sq(v1.y * v2.z - v1.z * v2.y) + sq(v1.z * v2.x - v1.x * v2.z));
}

template<typename T>
Vector get_vector(const Point<T>& frm, const Point<T>& to) {
    return Vector(to.x - frm.x, to.y - frm.y, to.z - frm.z);
}

int z_lim = 1000020;
// int z_lim = 20;
vector<vector<pair<int, vector<fltype>>>> events(z_lim);

void add_triangle(vector<Point<itype>> points) {
    assert(points.size() == 3);
    sort(points.begin(), points.end(), [](const Point<itype>& a, const Point<itype>& b) {
        if (a.z != b.z) return a.z > b.z;
        else return a.id < b.id;
    });

    int id = points[0].id;

    if (points[2].z == points[0].z) {
        Vector v1 = get_vector(points[0], points[1]);
        Vector v2 = get_vector(points[0], points[2]);
        fltype area = calc_area(v1, v2);
        int z = points[0].z;
        vector<fltype> c = { 0, 0, area };
        events[z].emplace_back(id, c);
        // vector<fltype> mc = { 0, 0, -area };
        // events[z - 1].emplace_back(id, mc);
        return;
    }
    if (points[2].z == points[1].z) {
        Vector v1 = get_vector(points[0], points[1]);
        Vector v2 = get_vector(points[0], points[2]);
        fltype area = calc_area(v1, v2);
        fltype dz = abs(v1.z);
        fltype ratio = 1 / dz;
        fltype unit_area = area * ratio * ratio;
        int z1 = points[0].z;
        int z2 = points[2].z;
        vector<fltype> c = { unit_area, -2 * unit_area * z1, unit_area * z1 * z1 };
        events[z1].emplace_back(id, c);
        vector<fltype> mc = { -unit_area, 2 * unit_area * z1, -unit_area * z1 * z1 + area };
        events[z2].emplace_back(id, mc);
        return;
    }
    if (points[0].z == points[1].z) {
        Vector v1 = get_vector(points[0], points[2]);
        Vector v2 = get_vector(points[1], points[2]);
        fltype area = calc_area(v1, v2);
        fltype dz = abs(v1.z);
        fltype ratio = 1 / dz;
        fltype unit_area = area * ratio * ratio;
        int z1 = points[0].z;
        int z2 = points[2].z;
        vector<fltype> c = { -unit_area, 2 * unit_area * z2, -unit_area * z2 * z2 + area };
        events[z1].emplace_back(id, c);
        vector<fltype> mc = { unit_area, -2 * unit_area * z2, unit_area * z2 * z2 };
        events[z2].emplace_back(id, mc);
        return;
    }

    {
        Vector v1 = get_vector(points[0], points[1]);
        Vector _v2 = get_vector(points[0], points[2]);
        fltype _ratio = abs(v1.z / _v2.z);
        Vector v2(_v2.x * _ratio, _v2.y * _ratio, _v2.z * _ratio);
        fltype area = calc_area(v1, v2);
        fltype dz = abs(v1.z);
        fltype ratio = 1 / dz;
        fltype unit_area = area * ratio * ratio;
        int z1 = points[0].z;
        int z2 = points[1].z;
        vector<fltype> c = { unit_area, -2 * unit_area * z1, unit_area * z1 * z1 };
        events[z1].emplace_back(id, c);
        vector<fltype> mc = { -unit_area, 2 * unit_area * z1, -unit_area * z1 * z1 + area };
        events[z2].emplace_back(id, mc);
    }
    {
        Vector _v1 = get_vector(points[0], points[2]);
        Vector v2 = get_vector(points[1], points[2]);
        fltype _ratio = abs(v2.z / _v1.z);
        Vector v1(_v1.x * _ratio, _v1.y * _ratio, _v1.z * _ratio);
        fltype area = calc_area(v1, v2);
        fltype dz = abs(v2.z);
        fltype ratio = 1 / dz;
        fltype unit_area = area * ratio * ratio;
        int z1 = points[1].z;
        int z2 = points[2].z;
        vector<fltype> c = { -unit_area, 2 * unit_area * z2, -unit_area * z2 * z2 + area };
        events[z1].emplace_back(id, c);
        vector<fltype> mc = { unit_area, -2 * unit_area * z2, unit_area * z2 * z2 };
        events[z2].emplace_back(id, mc);
    }
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    vector<Point<itype>> v(n);
    vector<vector<int>> points(z_lim);
    for (int i = 0; i < n; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        z += 10;
        v[i] = Point<itype>(i, x, y, z);
        points[z].push_back(i);
    }
    int m;
    cin >> m;
    vector<vector<int>> edge(n);
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        --z;
        add_triangle({ v[x], v[y], v[z] });
        edge[x].push_back(y);
        edge[y].push_back(x);
        edge[x].push_back(z);
        edge[z].push_back(x);
        edge[y].push_back(z);
        edge[z].push_back(y);
    }
    int q;
    cin >> q;
    vector<vector<P>> queries(z_lim);
    for (int i = 0; i < q; ++i) {
        int z, p;
        cin >> z >> p;
        z += 10;
        --p;
        queries[z].emplace_back(p, i);
    }

    vector<fltype> ans(q);

    dsu uf(n);

    vector<vector<fltype>> c(n, vector<fltype>(3));

    // vector<Point<itype>> v(3);
    // for (int i = 0; i < 3; ++i) {
    //     int x, y, z;
    //     cin >> x >> y >> z;
    //     v[i] = Point<itype>(i, x, y, z);
    // }
    // add_triangle(v);
    for (int z = z_lim - 1; z >= 0; --z) {
        for (auto& que : queries[z]) {
            int i = que.first;
            if (v[i].z <= z) {
                ans[que.second] = -1;
            }
            else {
                int j = uf.leader(i);
                fltype area = c[j][0] * z * z + c[j][1] * z + c[j][2];
                ans[que.second] = area;
            }
        }

        for (auto& i : points[z]) {
            for (auto& j : edge[i]) {
                if (v[j].z >= z && !uf.same(i, j)) {
                    int pi = uf.leader(i);
                    vector<fltype> ci = c[pi];
                    int pj = uf.leader(j);
                    vector<fltype> cj = c[pj];
                    int l = uf.merge(i, j);
                    for (int k = 0; k < 3; ++k) {
                        c[l][k] = ci[k] + cj[k];
                    }
                }
            }
        }

        for (auto& i : events[z]) {
            for (int j = 0; j < 3; ++j) {
                c[uf.leader(i.first)][j] += i.second[j];
            }
        }

    }
    cout << setprecision(16);
    for (auto& i : ans) {
        cout << i << '\n';
    }


    return 0;
}