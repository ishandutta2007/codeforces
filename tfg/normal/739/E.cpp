#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int maxn = 2020;
const double eps = 1e-8;
int n, a, b, opt[maxn];
double dp[maxn], pa[maxn], pb[maxn], pab[maxn];

pii solve(double &D, double &C){
    for(int i = 1; i <= n; i++){
        double &d = dp[i];
        int &o = opt[i];

        d = dp[i - 1];
        o = 0;

        if(d < dp[i - 1] + pa[i] - D){
            d = dp[i - 1] + pa[i] - D;
            o = 1;
        }

        if(d < dp[i - 1] + pb[i] - C){
            d = dp[i - 1] + pb[i] - C;
            o = 2;
        }

        if(d < dp[i - 1] + pab[i] - C - D){
            d = dp[i - 1] + pab[i] - C - D;
            o = 3;
        }
    }

    pii ret = pii(0, 0);

    for(int i = 1; i <= n; i++){
        if(opt[i] > 1)
            ret.second++;

        if(opt[i] & 1)
            ret.first++;
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);

    cin >> n >> a >> b;

    for(int i = 1; i <= n; i++)
        cin >> pa[i];

    for(int i = 1; i <= n; i++)
        cin >> pb[i];

    for(int i = 1; i <= n; i++)
        pab[i] = pa[i] + pb[i] - pa[i] * pb[i];

    double lo = 0, hi = 1, mid, lo2, hi2, mid2;

    for(int it2 = 0; it2 < 50; it2++){
        mid = (lo + hi) / 2;

        lo2 = 0, hi2 = 1, mid2;

        for(int it = 0; it < 50; it++){
            mid2 = (lo2 + hi2) / 2;

            if(solve(mid, mid2).second > b)
                lo2 = mid2;
            else
                hi2 = mid2;
        }

        if(solve(mid, hi2).first > a)
            lo = mid;
        else
            hi = mid;
    }

    solve(hi, hi2);

    cout << fixed << setprecision(10) << dp[n] + hi2 * b + hi * a << endl;

    return 0;
}