//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); ++it)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); ++rit)
#define ii pair<int, int>
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define maxN 100005
#define oo 1000000007
#define EPS 10e-9

char s[maxN];
vector<ii> ans;
int n, z[maxN], p[maxN], q[maxN];

void buildPF() {
    int j = 0; p[0] = 0;
    fto(i, 1, n-1) {
        while (j > 0 && s[i] != s[j]) j = p[j-1];
        if (s[i] == s[j]) ++j;
        p[i] = j;
    }
}

void buildZF() {
    int l = 0, r = 0; z[0] = n;
    fto(i, 1, n-1) {
        if (i <= r) z[i] = min(r-i+1, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) ++z[i];
        if (i+z[i]-1 > r) l = i, r = i+z[i]-1;
    }
}

int main() {
    scanf("%s", s); n = strlen(s);

    buildPF();
    buildZF();

    fto(i, 0, n-1) q[i] = z[i];
    sort(q, q+n);

    int i = n-1, j = n-1;
    while (i != -1) {
        while (j >= 0 && q[j] > i) --j;
        ans.pb(mp(i+1, n-j-1));
        i = p[i]-1;
    }
    printf("%d\n", ans.size());
    forrit(rit, ans) printf("%d %d\n", rit->ff, rit->ss);

    return 0;
}