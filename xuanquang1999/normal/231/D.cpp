using namespace std;
#include <bits/stdc++.h>
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
#define maxN 105
#define maxM 10005
#define maxC 1000000009

int x, y, z, x1, z1, a1, a2, a3, a4, a5, a6, ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int y1;
    scanf("%d%d%d", &x1, &y1, &z1);
    scanf("%d%d%d", &x, &y, &z);
    scanf("%d%d%d%d%d%d", &a1, &a2, &a3, &a4, &a5, &a6);

    if (y1 < 0) ans+=a1;
    if (y1 > y) ans+=a2;
    if (z1 < 0) ans+=a3;
    if (z1 > z) ans+=a4;
    if (x1 < 0) ans+=a5;
    if (x1 > x) ans+=a6;

    printf("%d", ans);

    return 0;
}