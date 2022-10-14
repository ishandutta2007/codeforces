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
typedef int ll;
using namespace std;
ll n,m,k,x, rt[35], y, z, l, i, j, p[335];
char a[255][255];
ll b[255][35];
ll hsh[335], prhs[335], sufhs[335];
ll get_sufhash(ll l, ll r) {
    return sufhs[l] - sufhs[r+1] * p[r-l+1];
}

ll get_prefhash(ll l, ll r) {
    return prhs[r+1] - prhs[l] * p[r-l+1];
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m;
    p[0] = 1;
    for (int i = 1; i < 300; i++)
        p[i] = p[i-1] * 228228227;
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);
    ll ans = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < 26; k++)
                b[i][k] = 0;
        }
        for (int k = j; k < m; k++) {
            for (int i = 0; i < n; i++) {
                b[i][a[i][k]-'a']++;
            }
            for (int i = 0; i < n; i++) {
                ll cnt = 0;
                for (int l = 0; l < 26; l++)
                    cnt += b[i][l] % 2;
                if (cnt > 1)
                    hsh[i] = 1337 + i;
                else {
                    hsh[i] = 0;
                    for (int l = 0; l < 26; l++) {
                        hsh[i] = 1LL*hsh[i]*283 + b[i][l];
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                prhs[i+1] = prhs[i] * 228228227 + hsh[i];
            }

            for (int i = n-1; i >= 0; i--) {
                sufhs[i] = sufhs[i+1] * 228228227 + hsh[i];
            }

            for (int i = 0; i < n; i++) {
                if (hsh[i] == 1337+i)
                    continue;
                ll l = 0, r = min(i, n-1-i);
                while (l < r) {
                    ll mid = (l+r+1)/2;
                    if (get_sufhash(i+1, i+mid) == get_prefhash(i-mid, i-1)) {
                        l = mid;
                    } else {
                        r = mid-1;
                    }
                }
                ans += l + 1;
            }

            for (int i = 0; i+1 < n; i++) {
                if (hsh[i] != hsh[i+1])
                    continue;
                ll l = 1, r = min(i+1, n-1-i);
                while (l < r) {
                    ll mid = (l+r+1)/2;
                    if (get_sufhash(i+1, i+mid) == get_prefhash(i-mid+1, i)) {
                        l = mid;
                    } else {
                        r = mid-1;
                    }
                }
                ans += l;
            }
        }
    }
    cout << ans << endl;
    return 0;
}