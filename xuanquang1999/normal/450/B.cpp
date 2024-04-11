using namespace std;
#include <bits/stdc++.h>
#define debug(a) cout << #a << ": " << a << endl
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 200005
#define mod 1000000007

int n, x, y, f[7];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &x, &y);
    scanf("%d", &n);

    f[1] = (x < 0) ? x+mod : x;
    f[2] = (y < 0) ? y+mod : y;
    fto(i, 3, 6) {
        f[i] = (f[i-1]-f[i-2])%mod;
        while (f[i] < 0) f[i]+=mod;
    }

    printf("%d", f[(n-1)%6+1]);


    return 0;
}