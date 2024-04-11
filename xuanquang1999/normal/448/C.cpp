using namespace std;
#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define ii pair<int, int>
#define mp make_pair
#define pb push_back
#define maxN 5005
#define maxC 2000000007
int n, a[maxN];

int calc(int l, int r, int h) {
    if (l > r) return 0;
    int pos = 0, ans = maxC;
    fto(i, l, r)
        if (a[i]-h < ans) {
            ans = a[i]-h;
            pos = i;
        }
    int p1 = calc(l, pos-1, h+ans) + calc(pos+1, r, h+ans) + ans;
    int p2 = r-l+1;
    return min(p1, p2);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);
    printf("%d", calc(0, n-1, 0));

    return 0;
}