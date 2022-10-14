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
#define IN 5
#define OR 10
#define AND 15
#define XOR 20
#define NOT 25
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, cnt,v,tot,x,y,INF, sz;
ll a[200500], answers[200500], w[200500];
ll price[5005];
ll b[5005][5005];
char s[25];
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n >> m >> q;
    //n = 12, m = 500000, q = 500000;
    for (int i = 0; i < n; i++) {
        cin >> w[n-1-i];
        //w[n-1-i] = i+1;
    }

    ll N = (1<<n);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < n; j++)
            if ((i&(1<<j)) != 0)
                price[i] += w[j];
    }
    for (int i = 0; i < m; i++) {
        scanf("%s", s);
        ll cur_num = 0;
        for (int j = 0; j < n; j++)
            cur_num += (s[j]-'0')*(1<<(n-j-1));
        //cur_num = (i&((1<<n)-1));
        a[cur_num]++;
    }
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            b[j][price[j^(N-1-k)]] += a[k];
        }
        for (int k = 1; k <= n*105; k++) {
            b[j][k] += b[j][k-1];
        }
    }

    for (int i = 0; i < q; i++) {
        scanf("%s %d", s, &x);
        ll cur_num = 0;
        for (int j = 0; j < n; j++)
            cur_num += (s[j]-'0')*(1<<(n-j-1));

        //cur_num = (i&((1<<n)-1)), x = 15;
        printf("%d\n", b[cur_num][x]);
    }
    return 0;
}