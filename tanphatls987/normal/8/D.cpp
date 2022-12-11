#include <bits/stdc++.h>

using namespace std;

#define double long double
const double eps = 1e-12;

struct point{
    double x, y;
    point(double x, double y) : x(x), y(y) {
    }
    point operator -(point oth) {
        return point(x - oth.x, y - oth.y);
    }
    point operator +(point oth) {
        return point(oth.x + x, oth.y + y);
    }
    double operator *(point oth) {
        return x * oth.x + y * oth.y;
    }
    point operator *(double k) {
        return point(x * k, y * k);
    }
    static double len(point a) {
        
        return sqrt(a * a);
    }
    point rotate(double ang) {
        return point(x * cos(ang) - y * sin(ang),
            x * sin(ang) + y * cos(ang));
    }
};

struct circle{
    point cen;
    double rad;
    circle (point cen, double rad) : cen(cen), rad(max(rad, eps)) {
    }
    vector<point> cross(circle oth) {
        double diff = point::len(oth.cen - cen);
        //assert(diff > eps);
        if (abs(diff - oth.rad - rad) < eps) {
            return {cen + (oth.cen - cen) * (rad / diff)};
        }
        if (diff > rad + oth.rad) return vector<point>();
        if (diff + oth.rad < rad) return vector<point>();
        if (diff + rad < oth.rad) return vector<point>();

        double angle = acos((rad * rad + diff * diff - oth.rad * oth.rad)
            / (2 * rad * diff));
        point dir = (oth.cen - cen) * (1.0 / diff);
        return {point(cen + dir.rotate(angle) * rad), point(cen + dir.rotate(-angle) * rad)};
    }
    bool inside(point a) {
        return point::len(cen - a) < rad + eps;
    }
};

double tol1, tol2;
int len1, len2;
vector<point> a;

bool check(double mid) {
    vector<circle> b = {circle(a[0], mid), circle(a[1], tol1 - mid),
        circle(a[2], tol2 - mid)};

    vector<point> imp;
    //cout << "?" << mid << '\n';
    for(int i = 0; i < 3; i++) {
        //cout << b[i].cen.x << " " << b[i].cen.y << " " << b[i].rad << '\n'; 
        for(int j = i + 1; j < 3; j++) {
            for(auto dat : b[i].cross(b[j])) {
                imp.push_back(dat);
                //cout << i << " " << j << " " <<"tick\n";
            }
        }
        imp.push_back(a[i]);
    }

    
    for(auto can : imp) {
        bool okay = 1;
        //cout << can.x << " " << can.y << '\n';
        for(auto i : b) okay &= i.inside(can);
        if (okay) return 1;
    }
    return 0;
}
double solve() {
    double goodfr = point::len(a[2] - a[0]) + point::len(a[1] - a[2]);
    if (tol1 >= goodfr) {
        return min(tol1, goodfr + len2); 
    }
    double L = 0, R = min(tol1, tol2);
    for(int i = 1; i <= 1000; i++){
        double mid = (L + R) / 2;
        if (check(mid)) L = mid;
        else R = mid;
    }
    return L;
}
int main() {
    cin >> len2 >> len1;
    for(int i = 0; i < 3; i++) {
        int x, y;
        cin >> x >> y; 
        a.push_back(point(x, y));
    }
    tol1 = point::len(a[1] - a[0]) + len1;
    tol2 = point::len(a[2] - a[0]) + len2;
    //cout << tol1 << " " << tol2 << '\n';
    double L = solve();

    printf("%.9Lf", L);
}