using namespace std;
#include <bits/stdc++.h>
#define fto(i, l, r) for(int i = l; i <= r; ++i)
int a[1025], n, k, ans;

int Balance(int i) {
    int l = 2*i, r = 2*i+1;
    if (l > k) return 0;

    int sl = a[l]+Balance(l), sr = a[r]+Balance(r);
    int x = max(sl, sr), y = min(sl, sr);
    ans+=x-y;
    return x;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    k = round(pow(2, n+1))-1;
    fto(i, 2, k) scanf("%d", &a[i]);

    Balance(1);

    printf("%d", ans);
}