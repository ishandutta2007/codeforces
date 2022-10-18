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
#define maxN 1005
#define oo 1000000007
#define EPS 10e-9

int k, e2;
string s[maxN];

int main() {
    scanf("%d%d", &k);
    s[0] = "+";
    e2 = 1;
    fto(i, 1, k) {
        fto(j, e2, e2*2-1) {
            s[j] = s[e2*2-1-j];
            fto(k, 0, e2-1) {
                if (s[j][k] == '+') s[j][k] = '*';
                else s[j][k] = '+';
            }
        }
        fto(j, e2, e2*2-1) s[j] = s[e2*2-j-1] + s[j];
        fto(j, 0, e2-1) s[j] = s[j] + s[j];
        e2*=2;
    }

    fto(i, 0, e2-1) cout << s[i] << endl;

    return 0;
}