using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
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
#define maxN 300005

int n, k, a[maxN], cnt0, cnt1, l0, l1;
vector<int> f[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &k);
    fto(i, 1, n) scanf("%d", &a[i]);
    sort(a+1, a+n+1);

    l1 = n/k+1;
    l0 = n/k;
    cnt1 = n%k;
    cnt0 = (n-cnt1*l1)/l0;

//    debug(cnt1);
//    debug(cnt0);
//    debug(l0);
//    debug(l1);

    f[0].pb(0);
    fto(j, 1, cnt1) f[0].pb(f[0][j-1]+a[j*l1]-a[(j-1)*l1+1]);
    //return 0;
    fto(i, 1, cnt0) {
        f[i].pb(f[i-1][0] + a[i*l0]-a[(i-1)*l0+1]);
        fto(j, 1, cnt1) f[i].pb(min(f[i-1][j]+a[j*l1+i*l0]-a[j*l1+(i-1)*l0+1], f[i][j-1]+a[j*l1+i*l0]-a[i*l0+(j-1)*l1+1]));
    }

//    fto(i, 0, cnt0) {
//        fto(j, 0, cnt1) printf("%d ", f[i][j]);
//        printf("\n");
//    }

    printf("%d", f[cnt0][cnt1]);

    return 0;
}