#include <bits/stdc++.h>

using namespace std;

typedef pair<double, double> ii;
#define X first
#define Y second

double dist(ii a, ii b) {
    double dx = min(abs(a.X - b.X), 4e9 + 5) , dy = min(abs(a.Y - b.Y), 4e9 + 5);
    return sqrt(dx * dx + dy * dy);
}
int main() {
    long long a, b, c, xa, xb, ya, yb;
    cin >> a >> b >> c;
    cin >> xa >> ya >> xb >> yb;
    
    vector<ii> p1, p2;
    if (b != 0) {
        p1.push_back(ii(xa, (c + a * xa + .0) / -b));
        p2.push_back(ii(xb, (c + a * xb + .0) / -b));
    }
    if (a != 0) {
        p1.push_back(ii((c + b * ya + .0) / -a, ya));
        p2.push_back(ii((c + b * yb + .0) / -a, yb));
    }
    double ans = abs(xa - xb) + abs(ya - yb);
    for(auto u1 : p1) 
        for(auto u2 : p2) ans = min(ans, 
            dist(ii(xa, ya), u1) + dist(u1, u2) + dist(u2, ii(xb, yb))); 
    printf("%.9f", ans);
}