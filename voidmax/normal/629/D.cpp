#include <iostream>
#include <vector>
#include <map>
#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <fstream>
#define For(i, a, b) for(int i = a; i < b; ++i)
#define Out(i, a, b) for(int i = a - 1; i >= b; --i)
#define pb push_back
#define point pair <base, base>
#define x first
#define y second

using namespace std;

typedef long long base;

int n;

long double M_Pi = 3.14159265358979323846264338327950288;

long double V(long double r, long double h) {
    return M_Pi * r * r * h;
}

map <base, long double> ans;

void relacs(pair <base, long double> a) {
    auto It = ans.lower_bound(a.x); ++It;
    if (It == ans.end()) return;
    if ((*It).y < a.y) {
        ans.erase(It);
        relacs(a);
    }
}

void add(base r, base h) {
    base V1 = r * r * h;
    auto It = ans.lower_bound(V1);
    if (ans.begin() == It) return;
    --It;
    pair <base, long double> New = *It;
    New.x = V1;
    New.y += V(r, h);
    
    It = ans.lower_bound(New.x);
    if (ans.begin() != It) {
        --It;
        if ((*It).y >= New.y) {
            return;
        }
    }
    ans[New.x] = max(ans[New.x], New.y);
    relacs(New);
}



int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    ans[0] = 0;
    For(i, 0, n) {
        int r, h; cin >> r >> h;
        add(r, h);
    }
    auto It = ans.end(); --It;
    cout << fixed << (*It).y << endl;
}

/*
2 2 8
3 1 9
5 1 25
4 3 48
48 + 25 + 9 + 8
*/