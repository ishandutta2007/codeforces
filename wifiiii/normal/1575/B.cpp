#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const double pi = acos(-1.0);
const double eps = 1e-8;
mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    double lo = 0, hi = 2e5;
    for(int q = 0; q <= 35; ++q) {
        double r = (lo + hi) / 2;
        vector<pair<double,double>> segs;
        vector<double> aa;
        for(int i = 0; i < n; ++i) {
            if(1ll * a[i] * a[i] + 1ll * b[i] * b[i] <= 4 * r * r) {
                double dt = acos(min(1.0, sqrt(1ll * a[i] * a[i] + 1ll * b[i] * b[i]) / 2 / r));
                double t = atan2(b[i], a[i]); // -pi ~ pi
                // [t - dt, t + dt]
                segs.push_back({t - dt, t + dt});
                aa.push_back(t - dt);
                aa.push_back(t + dt);
                if(t - dt <= -pi - eps) {
                    segs.push_back({t - dt + pi + pi, t + dt + pi + pi});
                    aa.push_back(t - dt + 2 * pi);
                    aa.push_back(t + dt + 2 * pi);
                }
                if(t + dt >= pi + eps) {
                    segs.push_back({t - dt - pi - pi, t + dt - pi - pi});
                    aa.push_back(t - dt - 2 * pi);
                    aa.push_back(t + dt - 2 * pi);
                }
            }
        }
        sort(aa.begin(), aa.end());
        aa.resize(unique(aa.begin(), aa.end()) - aa.begin());
        auto f = [&](double x) {return lower_bound(aa.begin(), aa.end(), x) - aa.begin();};
        vector<int> c(aa.size()+1);
        for(auto [x, y] : segs) {
            c[f(x-eps)] += 1;
            c[f(y-eps)] -= 1;
        }
        for(int i = 1; i <= aa.size(); ++i) c[i] += c[i-1];
        if(*max_element(c.begin(), c.end()) >= k) hi = r;
        else lo = r;
    }
    cout << fixed << setprecision(10) << lo << endl;
}