#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 500;

int A[N], B[N], n, c;
long long mn[N];

void solve(){
        scanf("%d%d", &n, &c);
        for(int i = 0;i < n;i++){
                scanf("%d", A + i);
        }
        long long bal = 0, ans = (c + A[0] - 1) / A[0];
        for(int i = 1;i < n;i++){
                scanf("%d", B + i);
                long long bonus = max(0LL, (B[i] - bal + A[i - 1] - 1) / A[i - 1]);
                mn[i] = mn[i - 1] + bonus + 1;
                //printf("dan %i:  %lld %lld\n", i, mn[i], bal);
                bal += bonus * A[i - 1] - B[i];
                ans = min(ans, mn[i] + (c - bal + A[i] - 1) / A[i]);
        }
        printf("%lld\n", ans);
}

int main(){
        int t;
        scanf("%d", &t);
        while(t--)
                solve();
        return 0;
}