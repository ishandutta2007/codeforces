#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>
#include <iomanip>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

struct point {
    double x, y;
    point() { x = y = 0.0; }
    point(double _x, double _y) : x(_x), y(_y) {}
    point operator +(point other) const{
        return point(x + other.x, y + other.y);
    }
    point operator -(point other) const{
        return point(x - other.x, y - other.y);
    }
    point operator *(double k) const{
        return point(x*k, y*k);
    }
    double norm() {
        return hypot(x, y);
    }
    point normalized() {
        return point(x,y)*(1.0/norm());
    }
};

double dist(point p1, point p2) {
    return hypot(p1.x - p2.x, p1.y - p2.y);
}

double dist2(point p) {
    return p.x * p.x + p.y * p.y;
}

double cross(point p1, point p2) {
    return p1.x*p2.y - p1.y*p2.x;
}

double getAngle(point a, point b) {
    if(cross(a, b) < 0) std::swap(a, b);
    double angle = atan2(cross(a, b),a.x*b.x + a.y*b.y);
    if(angle < 0) angle += acos(-1.0) * 2;
    return angle;
}

double func(point a, point b, point c) {
    const double LIM = acos(-1.0) * 2.0 / 3.0;
    //std::cout << LIM << ", (" << getAngle(b-a, c-a) << ", " << getAngle(a-b, c-b) << ", " << getAngle(a-c, b-c) << ")\n";
    if(getAngle(b-a, c-a) >= LIM) {
        return dist(b, a) + dist(c, a);
    } else if(getAngle(a-b, c-b) >= LIM) {
        return dist(a, b) + dist(c, b);
    } else if(getAngle(a-c, b-c) >= LIM) {
        return dist(a, c) + dist(b, c);
    }
    double sides = dist2(a-b) + dist2(a-c) + dist2(b-c);
    return sqrt((sides + 2 * sqrt(3) * fabs(cross(b-a, c-a))) / 2);
}

int main() {
    std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
    point a[3];
    for(int i = 0; i < 3; i++) {
        std::cin >> a[i].x >> a[i].y;
    }
    auto eval = [&](point pos) {
        double ans = 0.0;
        for(int i = 0; i < 3; i++) for(int j = i+1; j < 3; j++) {
            double val = func(pos, a[i], a[j]);
            ans = std::max(ans, val);
            //std::cout << val << std::endl;
        }
        return ans;
    };
    point ans;
    double best = eval(ans);
    std::uniform_real_distribution<double> rDist(0, 1), aDist(0, acos(-1)*2);
    double alpha = 1e4;
    for(int rep = 0; rep < 1000000; rep++) {
        double r = rDist(rng);
        r = alpha;
        double angle = aDist(rng);
        point nxt(cos(angle) * r, sin(angle) * r);
        nxt = nxt + ans;
        auto got = eval(nxt);
        if(got < best) {
            best = got;
            ans = nxt;
        }
        alpha = std::max(alpha*0.9999, 0.000001);
    }
    std::cout << std::fixed << std::setprecision(10) << best << '\n';
}