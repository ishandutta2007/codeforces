#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const double eps = 1e-10;
int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        double c, p, m, v;
        cin >> c >> m >> p >> v;
        double ans = p;
        for(int len = 1; len <= 18; ++len) {
            double tot = 0;
            for(int i = 0; i < 1 << len; ++i) {
                double cc = c, pp = p, mm = m, prob = 1;
                for(int j = 0; j < len; ++j) {
                    if(i >> j & 1) {
                        // C
                        prob *= cc;
                        if(prob == 0) break;
                        if(cc <= v + eps) {
                            if(mm > eps) {
                                mm += cc / 2;
                                pp += cc / 2;
                            } else {
                                pp += cc;
                            }
                            cc = 0;
                        } else {
                            cc -= v;
                            if(mm > eps) {
                                mm += v / 2;
                                pp += v / 2;
                            } else {
                                pp += v;
                            }
                        }
                    } else {
                        // M
                        prob *= mm;
                        if(prob == 0) break;
                        if(mm <= v + eps) {
                            if(cc > eps) {
                                cc += mm / 2;
                                pp += mm / 2;
                            } else {
                                pp += mm;
                            }
                            mm = 0;
                        } else {
                            mm -= v;
                            if(cc > eps) {
                                cc += v / 2;
                                pp += v / 2;
                            } else {
                                pp += v;
                            }
                        }
                    }
                }
                // P
                prob *= pp;
                tot += prob;
            }
            ans += (len + 1) * tot;
        }
        cout << fixed << setprecision(10) << ans << '\n';
    }
}