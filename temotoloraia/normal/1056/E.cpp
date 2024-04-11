#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
//#define temo

using namespace std;

const ll N = 1000007, P = 41, MOD = 1e9 + 9;

string s, S;
ll H[N];
ll A, B, t;
ll n, m;
ll p[N];
ll ans;

int main()
{
    cin>>s>>S;
    n = s.size();
    m = S.size();
    if (n > m){
        cout<<0<<endl;
        return 0;
    }
    s = "#" + s;
    S = "#" + S;
    for (int i = 1; i <= m; i++)
        H[i] = (H[i - 1] * P + (S[i] - 'a' + 1)) % MOD;
    p[0] = 1;
    for (int i = 1; i <= m; i++)
        p[i] = p[i - 1] * P % MOD;
    for (int i = 1; i <= n; i++){
        if (s[i] == s[1])
            A++;
        else
            B++;
    }
    for (int i = n; i >= 1; i--)
        if (s[i] != s[1])
            t = i;
    for (ll a = 1; A * a < m; a++){
        ll b = (m - A * a) / B;
        if (m != A * a + B * b)
            continue;
        ll X = H[a];
        ll Y = ((H[(t - 1) * a + b] - H[(t - 1) * a] * p[b]) % MOD + MOD) % MOD;
        if (X == Y)
            continue;
        ll I = 0;
        bool ok = 1;
        for (int i = 1; i <= n; i++){
            if (s[i] == s[1]){
                if (((H[I + a] - H[I] * p[a]) % MOD + MOD) % MOD != X){
                    ok = 0;
                    break;
                }
                I += a;
            }
            else {
                if (((H[I + b] - H[I] * p[b]) % MOD + MOD) % MOD != Y){
                    ok = 0;
                    break;
                }
                I += b;
            }
        }
        if (ok)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}