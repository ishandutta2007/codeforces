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
#define MOD 1000000007
typedef long long ll;
using namespace std;
ll n,m,k,x, rt[35], y, z, l, i, j, p[1005000];
ll a[100500], b[100500];
ll dp[100500];
vector<ll> f;
bool prime(ll x) {
    for (int i =2; i*i <= x; i++)
    if (x % i == 0) {
        return false;
    }
    return true;
}
ll prt[5] = {29, 31, 37, 41, 43};
ll hsh[1005000];
ll MO, M;
string bullshit = "sdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdfdgokfdjgkdfjgkdfjgkdfjgksdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmddfkgjdfkgjdfkgjsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdfdgokfdjgkdfjgkdfjgkdfjgksdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdfdgokfdjgkdfjgkdfjgkdfjgksdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdfdgokfdjgkdfjgkdfjgkdfjgksdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmsdflkgsdjkjgjsdkfhjksdkhndsklkfjglkdfjgldkfjherfawcsovgsdflkgsdjkjgjsdkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbmijfbmkfhjksdkhndsksdflkgsdjkjgjsdkfhjksdkhndsksmfbijmdijfbm";
ll get_hash(ll l, ll r) {
    return (hsh[r+1] - hsh[l] * p[r-l+1] + MO * MO) % MO;
}
int main() {
     //freopen("input.txt","r",stdin);
    for (int i = 1000000000; i <= 1000001000; i++)
    if (prime(i)) {
        f.push_back(i);
    }
    ll seed = 0;
    for (int i = 0; i < bullshit.size(); i++)
        seed = (seed * 29 + bullshit[i]) % MOD;
    srand(seed);
    int x = rand() % (int)f.size();
    MO = f[x];
    M = prt[rand()%5];
    p[0] = 1;
    for (int i = 1; i <= 1000100; i++)
        p[i] = p[i-1] * M % MO;
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++) {
        a[s[i]-'0']++;
    }
    int szt = t.size();
    for (int i = 0; i < szt; i++) {
        hsh[i+1] = (hsh[i] * M + t[i] - 'a' + 1) % MO;
    }
    ll ans = 0;
    for (int j = 1; j * a[0] < szt; j++) {
        if ((szt - j * a[0]) % a[1] != 0)
            continue;
        int k = (szt - j * a[0]) / a[1];
        ll has[2];
        has[0] = has[1] = -1;
        ll tr[2];
        tr[0] = j, tr[1] = k;
        ll flag = 1;
        ll pnt = 0;
        for (int i = 0; i < s.size(); i++) {
            ll cur_hash = get_hash(pnt, pnt + tr[s[i]-'0'] - 1);
            pnt += tr[s[i] - '0'];
            if (has[s[i]-'0'] == -1) {
                has[s[i] - '0'] = cur_hash;
            } else if (has[s[i]-'0'] != cur_hash) {
                flag = 0;
                break;
            }
        }
        if (has[0] == has[1])
            flag = 0;
        ans += flag;
    }
    cout << ans << endl;
    return 0;
}