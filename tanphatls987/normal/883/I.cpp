#include <bits/stdc++.h>

using namespace std;

const int N = 300005;

int n, k, a[N];
bool F[N];

bool check(int M) {
    int L = 1, index = 0;
    memset(F, false, sizeof F);
    F[0] = true;
    for (int i = k; i <= n; ++i) {
        while (L <= n && a[i]-a[L] > M) ++L;
        int R = i-k+1;
        if (L > R) {
            F[i] = false;
            continue;
        }
        while ((!F[index] || index < L-1) && index < i)
            ++index;
        if (index >= L-1 && index <= R-1 && F[index])
            F[i] = true;
    }
    return F[n];
}

int main() {
  //  freopen("input.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for (int i = 1; i <= n; ++i)
        scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    int L = 0, R = a[n]-a[1], res = a[n]-a[1];
    while (L <= R) {
        int M = (L+R)>>1;
        if (check(M)) {
            res = M;
            R = M-1;
        }
        else L = M+1;
    }
    cout << res << endl;
    return 0;
}