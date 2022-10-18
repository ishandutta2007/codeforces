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
#define maxN 200005
#define maxX 1000005
#define oo 1000000007

int d, n, a, b, ans, x[maxN];
map<int, int> m;
int minL[maxX];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &d);
    fto(i, 1, d) {
        int k;
        scanf("%d", &k);
        if (!m[k]) {
            x[++n] = k;
            m[k] = n;
        }
    }
    scanf("%d%d", &a, &b);
    //fto(i, 1, n) debug(x[i]);

    fto(i, 1, a-b) minL[i] = i-1;
    fto(i, 1, n) {
        if ((a/x[i])*x[i]-b >= 0) minL[a-b] = min(minL[a-b], (a/x[i])*x[i]-b);
    }
    fto(i, 1, n) {
        //debug(i);
        for(int j = ((b-1)/x[i]+1)*x[i]; j <= a; j+=x[i]) {
            //debug(j);
            if (j+x[i]-1-b <= a-b) minL[j+x[i]-1-b] = min(minL[j+x[i]-1-b], j-b);
        }
//        fto(j, 0, a-b) printf("%d ", minL[j]);
//        printf("\n");
    }
    //return 0;
    fdto(i, a-b-1, 0) {
        minL[i] = min(minL[i+1], minL[i]);
    }
//    fto(j, 0, a-b) printf("%d ", minL[j]);
//    printf("\n");

    int u = a-b;
    while (u > 0) {
        //debug(u);
        u = minL[u];
        ans++;
    }
    //debug(u);

    printf("%d", ans);


    return 0;
}