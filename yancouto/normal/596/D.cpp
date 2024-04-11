#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, h; double p;
int x[2003];

int rig(int p, int r, bool right, int hh=h) {
        return max(min(hh, (x[r + 1] - !right * h) - p), 0);
}
int lef(int p, bool left, int l, int hh=h) {
        return max(min(hh, p - (x[l - 1] + !left * h)), 0);
}

double memo[2][2005][2004][2];
int seen[2][2004][2004][2];
double solve(bool left, int l, int r, bool right) {
        if(l > r) return 0;
        double &ans = memo[left][l][r][right];
        if(seen[left][l][r][right]) return ans;
        seen[left][l][r][right] = 1;
        if(!left && x[l] - x[l - 1] < h) {
                ans = solve(false, l + 1, r, right);
                int diff = max(0, min(x[l] + h, x[r + 1] - !right * h) - (x[l - 1] + h));
                int ri = min(x[l] + h, x[r + 1] - !right * h);
                ans += max(0, min(x[l] + h, x[r + 1] - !right * h) - (x[l - 1] + h));
                //ans += rig(x[l - 1] + h, r, right, x[l] - x[l - 1]);
                return ans;
        }
        if(!right && x[r + 1] - x[r] < h) {
                ans = solve(left, l, r - 1, false);
                int diff = max(0, (x[r + 1] - h) - max(x[r] - h, x[l - 1] + !left * h));
                ans += max(0, (x[r + 1] - h) - max(x[r] - h, x[l - 1] + !left * h));
                //ans += lef(x[r + 1] - h, left, l, x[r + 1] - x[r]);
                return ans;
        }
        double crr = solve(left, l, r - 1, true) + rig(x[r], r, right);
        double cll = solve(true, l + 1, r, right) + lef(x[l], left, l);
        double crl = solve(left, l, r - 1, false) + lef(x[r], left, l);
        double clr = solve(false, l + 1, r, right) + rig(x[l], r, right);
        double cr = p * crl + (1. - p) * crr;
        double cl = p * cll + (1. - p) * clr;
        return ans = (cr + cl) * .5;
}

int main() {
        int i;
        scanf("%d %d %lf", &n, &h, &p);
        for(i = 0; i < n; i++)
                scanf("%d", &x[i]);
        x[n] = -300030000; x[n + 1] = 300003000;
        sort(x, x + n + 2);
        printf("%.15f\n", solve(true, 1, n, true));
}