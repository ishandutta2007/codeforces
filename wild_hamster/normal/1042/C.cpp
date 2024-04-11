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
#define N 1000005
typedef int ll;
using namespace std;
ll n,i,j,k,z,m,q,r,timer,mx,l, v,tot,x,y,INF, sz;
ll a[200500], used[200500];
vector<ll> f, g;
void print() {
    for (int i = 0; i < n; i++)
        if (!used[i])
            f.push_back(i);
        else
            g.push_back(i);
    if (f.empty() || g.empty()) {
        for (int i = 0; i+1 < n; i++)
            printf("1 %d %d\n", i+1, i+2);
        return;
    }
    for (int i = 0; i+1 < g.size(); i++)
        printf("1 %d %d\n", g[i]+1, g[i+1]+1);
    printf("2 %d\n", g.back()+1);
    for (int i = 0; i+1 < f.size(); i++) {
        printf("1 %d %d\n", f[i]+1, f[i+1]+1);
    }
}
int main() {
    //freopen("input.txt","r",stdin);
    cin >> n;
    int neg = 0, zeros = 0;
    int first_neg, first_zero;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] < 0) {
            if (neg == 0)
                first_neg = i;
            else if (a[i] > a[first_neg])
                first_neg = i;
            neg++;
        }
        if (a[i] == 0) {
            used[i] = 1;
            zeros++;
        }
    }
    if (neg%2) {
        used[first_neg] = 1;
    }
    print();
    return 0;
}