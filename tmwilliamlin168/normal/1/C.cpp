#include <bits/stdc++.h>
using namespace std;

typedef long long int64;

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) a.size() - 1
#define all(a) a.begin(), a.end()
#define I (int)
#define I64 (int64)
#define LD (long double)
#define VI vector<int>

const long double EPS = 1E-5;
const int INF = (int)1E9;
const int64 INF64 = (int64)1E18;
const long double PI = 2 * acos(.0);

long double getR(long double n, long double i, long double a){
    i = min(i, n - i);
    if (fabs(i*2.0 - n) < EPS) return 0.5 * a;
    return 0.5 * a / cos(PI * (0.5 - i/n));
}

void check(long double a, long double b, long double c, int N, long double &s){
    long double n = N;
    for(int i = 1; i < N; i++)
        for(int j = 1; j < N; j++)
            if (i != j){
                long double R1 = getR(n, i, a);
                long double R2 = getR(n, j, b);
                long double R3 = getR(n, abs(i - j), c);

                if (fabs(R1 - R2) < EPS && fabs(R1 - R3) < EPS && fabs(R3 - R2) < EPS)
                    s = min(s, n * 0.5 * R1*R1 * sin(2.0*PI / n));
            }
        

}

int main() {
    long double x1, y1; cin >> x1 >> y1;
    long double x2, y2; cin >> x2 >> y2;
    long double x3, y3; cin >> x3 >> y3;

    long double a = sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
    long double b = sqrt((x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2));
    long double c = sqrt((x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3));

    long double ans = 1E60;
    for(int i = 3; i <= 100; i++)
        check(a, b, c, i, ans);

    cout.precision(10);
    cout << fixed << ans << "\n";
}