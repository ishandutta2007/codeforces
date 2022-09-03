#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

#define filename ""

int n;
int m;
int x[3];

ll calc (int x) {
    re (ll)(x + 2) * (x + 1) / 2;
}

int main () {
    int sum = 0;
    for (int i = 0; i < 3; i++) {
        scanf ("%d", &x[i]);
        sum += x[i];
    }
    scanf ("%d", &m);
    ll ans = 0;
    for (int i = 0; i <= m; i++) {
        int mid = (sum + i - 1) / 2;
        if (x[0] > mid || x[1] > mid || x[2] > mid) continue;
        for (int j = 0; j < 8; j++) {
            int tmp = i;
            int q = 1;
            for (int k = 0; k < 3; k++)
                if ((j >> k) & 1) {
                    q = -q;
                    tmp -= (mid + 1) - x[k];
                }
            if (tmp < 0) continue;
            ans = ans + q * calc (tmp);
        }
    }
    cout << ans << endl;
    re 0;
}