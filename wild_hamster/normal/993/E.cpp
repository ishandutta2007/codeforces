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
#define ROW 5
#define COL 30000
typedef long long ll;
using namespace std;
typedef complex<double> base;
ll n,i,j,k,z,m,q,h,r,timer,mx,l, cnt, u,v,t,s,tot,x,y;
ll a[1200005], d[1205000];
base b[1200500], c[1200500], w[1200500];
ll indexes[1205000];
base new_arr[1205000];
void my_first_fft(base* a, ll l, ll p, ll invert) {
    ll r = 0;
    for (int i = 1; (1<<i) < y; i++) {
        r = i;
    }
    for (int i = r; i >= 0; i--) {
        ll sz = (y>>i);
        double ang = 2*PI*invert / sz;
        base w1(1), wn(cos(ang), sin(ang));
        for (int j = 0; j < sz/2; j++)
            w[j] = w1, w1 *= wn;
        for (int j = 0; j < (1<<i); j++) {
            for (int k = 0; k < sz/2; k++) {
                base rgt = w[k] * a[j+2*k*(1<<i) + (1<<i)];
                base lft = a[j+2*k*(1<<i)];
                new_arr[k] = lft + rgt;
                new_arr[k+sz/2] = lft - rgt;
            }
            for (int k = 0; k < sz; k++) {
                a[j+k*(1<<i)] = new_arr[k];
            }
        }
    }
    /*if (l + p >= y) {
        return;
    }
    my_first_fft(a, l, p*2, invert);
    my_first_fft(a, l+p, p*2, invert);
    ll pnt = 0;
    while (l < y) {
        indexes[pnt++] = l;
        l += p;
    }
    ll sz = pnt;

    double ang = 2*PI*invert / sz;
    base w(1), w1(cos(ang), sin(ang));
    for (int i = 0; i < sz/2; i++) {
        new_arr[i] = a[indexes[2*i]] + w*a[indexes[2*i+1]];
        new_arr[i+sz/2] = a[indexes[2*i]] - w*a[indexes[2*i+1]];
        w *= w1;
    }
    for (int i = 0; i < sz; i++)
        a[indexes[i]] = new_arr[i];*/
}

int main() {

    long long ans = 0;
    //freopen("input.txt","r",stdin);
    for (int i = 0; i <= 20; i++)
        d[1<<i] = 1;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        if (x < k)
            a[i] = 1;
    }
    for (int i = 1; i < n; i++)
        a[i] += a[i-1];
    b[0] = 1;
    x = 0;
    for (int i = 0; i < n; i++) {
        b[a[i]] += 1;
        x = max(x, a[i]);
    }

    for (int i = 0; i <= x; i++) {
        c[i] = b[i];
        ans += 1LL*(int)(b[i].real())*(int)(b[i].real()-1)/2;
    }

    ans += n+1;
    reverse(c, c+x+1);
    y = x+1;
    while (!d[y])
        y++;
    y *= 2;

    my_first_fft(b, 0, 1, 1);
    my_first_fft(c, 0, 1, 1);
    for (int i = 0; i < y; i++)
        b[i] *= c[i];
    my_first_fft(b, 0, 1, -1);
    for (int i = 0; i < y; i++) {
        b[i] /= y;
        if (i == x)
            b[i] -= ans;
    }
    for (int i = x; i >= 0; i--) {
        printf("%I64d ", (long long)(b[i].real()+0.5));
    }
    for (int i = 0; i <= n-x-1; i++)
        printf("0 ");
    return 0;
}