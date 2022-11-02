//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define pb push_back
#define X first
#define Y second
#define mp make_pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

ll ans;
ll buf[20];

//#define TEST

void solve(){
    ans = (ll)1e18;
    int x[4], y[4];
    for(int i = 0; i < 4; i++){
#ifdef TEST
        x[i] = y[i] = 0;
#else
        cin >> x[i] >> y[i];
#endif
    }
    int seq[4];
    for(int px = 0; px < 4; px++){
        for(int py = 0; py < 4; py++){
            int cx = x[px], cy = y[py];
            iota(seq, seq + 4, 0);
            do{
                for(int sgnx = -1; sgnx <= 1; sgnx += 2){
                    for(int sgny = -1; sgny <= 1; sgny += 2){
                        //pt 0
                        ll val = abs(x[seq[0]] - cx) + abs(y[seq[0]] - cy);
                        //pt 1
                        val += abs(x[seq[1]] - cx);
                        buf[0] = cy - y[seq[1]];
                        if(sgny == 1)buf[0] = -buf[0];
                        //pt 2
                        buf[1] = cx - x[seq[2]];
                        if(sgnx == 1)buf[1] = -buf[1];
                        buf[2] = cy - y[seq[2]];
                        if(sgny == 1)buf[2] = -buf[2];
                        //pt 3
                        val += abs(y[seq[3]] - cy);
                        buf[3] = cx - x[seq[3]];
                        if(sgnx == 1)buf[3] = -buf[3];
                        nth_element(buf, buf + 1, buf + 4);
                        ll d = buf[1];
                        for(int i = 0; i < 4; i++)
                            val += llabs(buf[i] - d);
                        ans = min(ans, val);
                    }
                }
            }while(next_permutation(seq, seq + 4));
        }
    }
    cout << ans << '\n';
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(3);
    int T=1;
#ifdef TEST
    T = 10000;
#else
    cin >> T;
#endif
    while(T--)
        solve();
    return 0;
}