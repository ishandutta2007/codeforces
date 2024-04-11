#include <iostream>
#include <vector>
#include <algorithm>

#define INF 1e9

using namespace std;

struct Point {
    int x, y;
    Point(int x = 0, int y = 0): x(x), y(y) {}
};

bool xCompare(const Point &p1, const Point &p2) {
    return p1.x < p2.x;
}

bool yCompare(const Point &p1, const Point &p2) {
    return p1.y < p2.y;
}

long long sqr(long long num) {
    return num * num;
}

long long distance(Point &p1, Point &p2) {
    int x = p1.x - p2.x;
    int y = p1.y - p2.y;
    return sqr(x) + sqr(y);
}

long long bruteForce(vector<Point> &point_set, int left, int right) {
    long long dist_min = INF;
    for(int i = left; i < right; ++i) {
        for(int j = i + 1; j < right; ++j) {
            dist_min = min(dist_min, distance(point_set[i], point_set[j]));
        }
    }
    return dist_min;
}

long long stripClosest(vector<Point> &point_set, int left, int right, int mid, long long dist_min) {
    Point point_mid = point_set[mid];
    vector<Point> splitted_points;
    for(int i = left; i < right; ++i) {
        if (sqr(point_set[i].x - point_mid.x) <= dist_min) {
            splitted_points.push_back(point_set[i]);
        }
    }

    sort(splitted_points.begin(), splitted_points.end(), yCompare);

    long long smallest = INF;
    int l = splitted_points.size();
    for(int i = 0; i < l; ++i) {
        for(int j = i + 1; j < l && sqr(splitted_points[i].y - splitted_points[j].y) < dist_min; ++j) {
            long long d = distance(splitted_points[i], splitted_points[j]);
            smallest = min(smallest, d);
        }
    }
    return smallest;
}

long long closestUtil(vector<Point> &point_set, int left, int right) {
    if (right - left <= 3)
        return bruteForce(point_set, left, right);

    int mid = (left + right) / 2;
    long long dist_left = closestUtil(point_set, left, mid);
    long long dist_right = closestUtil(point_set, mid + 1, right);
    long long dist_min = min(dist_left, dist_right);

    return min(dist_min, stripClosest(point_set, left, right, mid, dist_min));
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> pref(1, 0);
    for(int i = 0; i < n; ++i) {
        pref.push_back(pref[i] + a[i]);
    }

    vector<Point> point_set;
    for(int i = 0; i < n; ++i) {
        point_set.push_back(Point(i, pref[i + 1]));
    }

    sort(point_set.begin(), point_set.end(), xCompare);
    long long ans = closestUtil(point_set, 0, n);
    cout << ans << endl;

    return 0;
}