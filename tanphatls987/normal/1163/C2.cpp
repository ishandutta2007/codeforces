#include <bits/stdc++.h>

using namespace std;

#define int long long 
typedef pair<int, int> ii;

#define X first
#define Y second

int a[1005][2];
int n;

struct line{
    int a, b, c;
    line (int a, int b, int c) : a(a), b(b), c(c) {}
};
bool operator <(const line &p1, const line &p2) {
    if (p1.a != p2.a) return p1.a < p2.a;
    if (p1.b != p2.b) return p1.b < p2.b;
    if (p1.c != p2.c) return p1.c < p2.c;
    return 0;
}
line gen(int xa, int ya, int xb, int yb) {
    int dy = -(xa - xb), dx = ya - yb;
    if (dx == 0) dy = 1;
    if (dy == 0) dx = 1;

    if (dx < 0) dx *= -1, dy *= -1;
    int dz = -(dx * xa + dy * ya);
    int com = __gcd(__gcd(abs(dx), abs(dy)), abs(dz));
    return line(dx / com, dy / com, dz / com);
}
set<line> mSet;
map<ii, int> mMap;

ii gen(int dx, int dy) {
    int com = __gcd(abs(dx), abs(dy));
    //cout << dx << " " << dy << '\n';
    return ii(dx / com, dy / com);
}
void prepare() {
    cin >> n;
    for(int i = 0; i < n; i++) 
        cin >> a[i][0] >> a[i][1];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++) {
            line b = gen(a[i][0], a[i][1], a[j][0], a[j][1]);
            //cout << b.a << " " << b.b << " " << b.c << '\n';
            mSet.insert(gen(a[i][0], a[i][1], a[j][0], a[j][1]));
        }
    long long ans = 1LL * mSet.size() * (mSet.size() - 1) / 2;

    for(auto i : mSet) mMap[gen(i.a, i.b)]++;
    for(auto i : mMap) {
        ans -= 1LL * i.Y * (i.Y - 1) / 2;
        //cout << i.X.X << " " << i.X.Y << " " << i.Y << '\n';
    }
    cout << ans;
}
int32_t main() {
    prepare();
}