#include <iostream>
#include <vector>
#include <set>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define pb push_back
#define point pair <long double, long double>
#define x first
#define y second

using namespace std;

long double scalp(point a, point b) {
    return a.x * b.x + a.y * b.y;
}

long double crossp(point a, point b) {
    return a.x * b.y - a.y * b.x;
}

bool half(point a) {
    if (a.y > 0) return true;
    if (a.y < 0) return false;
    return a.x < 0;
}

bool cmp(point a, point b) {
    if (half(a) == half(b)) {
        return crossp(a, b) < 0;
    }
    return half(a) < half(b);
}

bool cmp1(pair <point, int> a, pair <point, int> b) {
    return cmp(a.x, b.x);
}

long double ange(point a, point b) {
    return abs(atan2l(crossp(a, b), scalp(a, b)));
}

int n;
int L = 0, R = 1;
vector <pair <point, int>> arr;

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    For(i, 0, n) {
        point a; cin >> a.x >> a.y;
        arr.push_back({a, i + 1});
    }
    sort(arr.begin(), arr.end(), cmp1);
    arr.push_back(arr[0]);
    For(i, 2, n + 1) {
        if (ange(arr[L].x, arr[R].x) > ange(arr[i - 1].x, arr[i].x)) {
            L = i - 1; R = i;
        }
    }
    cout << arr[L].y << ' ' << arr[R].y;
}