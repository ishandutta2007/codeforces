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
#define maxN 100005

int main () {
    #ifndef ONLINE_JUDGE
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n, min1, max1, min2, max2, min3, max3;
    scanf("%d", &n);
    scanf("%d%d", &min1, &max1);
    scanf("%d%d", &min2, &max2);
    scanf("%d%d", &min3, &max3);

    int t1 = min(max1, n-min2-min3);
    n-=t1;
    int t2 = min(max2, n-min3);
    int t3 = n-t2;

    printf("%d %d %d", t1, t2, t3);


    return 0;
}