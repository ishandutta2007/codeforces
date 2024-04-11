#include <bits/stdc++.h>
#define mp make_pair
#define X first
#define Y second
#define pii pair<ll,ll>
#define x1 dlfjl
#define x2 dkfj
#define x3 dflgkg
#define y1 dskgj
#define y2 dskfj
#define y3 dfhgdh
#define SQ 320
#define PI 3.14159265359
typedef long long ll;
using namespace std;
ll n,i,j,k,x,y,z,m,q,h,r,timer,mx,l,sum, ans, cnt;
ll a[100500];
ll primes[3005000];
ll b[2005];
ll primes1[49] = {1000000007,1000000009,1000000021,1000000033,1000000087,1000000093,1000000097,1000000103,1000000123,1000000181,1000000207,1000000223,1000000241,1000000271,1000000289,1000000297,1000000321,1000000349,1000000363,1000000403,1000000409,1000000411,1000000427,1000000433,1000000439,1000000447,1000000453,1000000459,1000000483,1000000513,1000000531,1000000579,1000000607,1000000613,1000000637,1000000663,1000000711,1000000753,1000000787,1000000801,1000000829,1000000861,1000000871,1000000891,1000000901,1000000919,1000000931,1000000933,1000000993};
ll prs[300500], rev[300500][3];
ll MOD[5];
ll pre[200500][26][3], p2[300500][3];
ll f1[30], f2[30];
set<ll> f;
ll Abs(ll x) {
    return x>0?x:-x;
}
bool prime(ll x) {
    for (int i = 2; i*i <= x; i++)
        if (x%i == 0)
            return false;
    return true;
}
ll binpow(ll x, ll y, ll m) {
    if (y == 0)
        return 1;
    ll tmp = binpow(x, y/2, m);
    tmp = (tmp*tmp)%m;
    if (y%2 == 0)
        return tmp;
    return x*tmp%m;
}

int main() {

    //freopen("input.txt","r",stdin);
    srand(time(0));
    for (int i = 0; i < 3; i++) {
        ll x = rand()%49;
        MOD[i] = primes1[x];

    }
    for (int k = 0; k < 3; k++) {
        p2[0][k] = 1;
        rev[0][k] = 1;
        for (int i = 1; i <= 300000; i++) {
            p2[i][k] = (p2[i-1][k]*3)%MOD[k];
            rev[i][k] = binpow(p2[i][k], MOD[k]-2, MOD[k]);
        }
    }
    for (int i = 2; i <= 3000000; i++)
        primes[i] = 1;
    for (int i = 2; i <= 3000000; i++)
    if (primes[i]) {
        prs[cnt++] = i;
        for (int j = i*2; j <= 3000000; j += i)
            primes[j] = 0;
    }
    string s;
    cin >> n >> m;
    cin >> s;
    for (int k = 0; k < 3; k++)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            if (j + 'a' != s[i]) {
                pre[i+1][j][k] = (pre[i][j][k] + p2[i][k]*2)%MOD[k];
            } else {
                pre[i+1][j][k] =(pre[i][j][k] + p2[i][k])%MOD[k];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int x, y, l;
        scanf("%d %d %d", &x, &y, &l);
        x--;
        y--;
        ll flag = 1;
        for (int k = 0; k < 3; k++) {
            for (int j = 0; j < 26; j++) {
                f1[j] = (pre[x+l][j][k]-pre[x][j][k]+MOD[k])%MOD[k]*rev[x][k]%MOD[k];
                f2[j] = (pre[y+l][j][k]-pre[y][j][k]+MOD[k])%MOD[k]*rev[y][k]%MOD[k];
                //if (i == 2)
                //    cout << f1[j] << " " << f2[j] << endl;
            }
            sort(f1, f1+26);
            sort(f2, f2+26);
            for (int j = 0; j < 26; j++) {
                //cout << f1[j] << " " << f2[j] << endl;
                if (f1[j] != f2[j])
                    flag = 0;
            }
        }
        if (flag == 1) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}