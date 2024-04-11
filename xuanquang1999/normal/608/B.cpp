//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 200005
#define oo 1000000007
#define EPS 10e-9

char a[maxN], b[maxN];
int db[maxN], na, nb;
ll ans;

int main() {
    scanf("%s", a); na = strlen(a);
    scanf("%s", b); nb = strlen(b);

    fto(i, 0, nb-1) {
        db[i] = ((b[i] == '1') ? 1 : 0) + ((i > 0) ? db[i-1] : 0);
    }

    fto(i, 0, na-1) {
        if (a[i] == '0') ans += db[nb-na+i]- ((i > 0) ? db[i-1] : 0);
        else ans += (nb-na+1) - (db[nb-na+i] - ((i > 0) ? db[i-1] : 0));
    }

    cout << ans;

    return 0;
}