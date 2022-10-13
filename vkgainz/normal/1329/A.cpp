#include<bits/stdc++.h>
const int SIZE = 100002;
int len[SIZE];
long long suffix_sum[SIZE];
void err() {puts("-1");}
void solve() {
    int N, M;
    scanf("%d%d", &N, &M);
    for(int i = 1; i <= M; i++) {
        scanf("%d", &len[i]);
        if(len[i] + i - 1 > N) {
            err();
            return;
        }
    }
    for(int i = M; i > 0; i--) {
        suffix_sum[i] = suffix_sum[i + 1] + len[i];
    }
    if(suffix_sum[1] < N) {
        err();
        return;
    }
    for(int i = 1; i <= M; i++) {
        printf("%lld", std::max((long long)i, N - suffix_sum[i] + 1));
        if(i < M) putchar(' ');
        else puts("");
    }
}
int main() {
    solve();
    return 0;
}