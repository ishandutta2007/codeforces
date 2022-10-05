#include <bits/stdc++.h>

const int N = 110;
using pii = std::pair <int, int>;

int comb(int n){
    return n * (n - 1) * (n - 2) / 6;
}

int to_ask[N], delta[N * N], ans[N];
int n;

/*pii answer(){
    int ans1 = 0;
    for (int i = 1; i <= n; ++ i){
        ans1 += comb(a[i]);
    }
    int ans2 = 0;
    for (int i = 1; i <= n - 2; ++ i){
        ans2 += a[i] * a[i + 1] * a[i + 2];
    }
    // printf("%d %d\n", ans1, ans2);
    return {ans1, ans2};
}*/

pii ask(int pos){
    //++ a[pos];
    printf("+ %d\n", pos);
    fflush(stdout);
    int ans1, ans2;
    scanf("%d%d", &ans1, &ans2);
    return {ans1, ans2};
    //return answer();
}

pii p[N];

int main(){
    scanf("%d", &n);
    scanf("%d%d", &p[0].first, &p[0].second);
    /*for (int i = 1; i <= n; ++ i){
        scanf("%d", &a[i]);
    }
    p[0] = answer();*/
    for (int i = 1; i < N; ++ i){
        delta[i * (i - 1) / 2] = i;
    }
    for (int i = 1; i <= n - 3; ++ i){
        to_ask[i] = n - i;
    }
    to_ask[n - 2] = to_ask[n] = 1;
    to_ask[n - 1] = 2;
    for (int i = 1; i <= n; ++ i){
        p[i] = ask(to_ask[i]);
    }
    ans[1] = delta[p[n].first - p[n - 1].first] - 1;
    ans[3] = (p[n].second - p[n - 1].second) - (p[n - 2].second - p[n - 3].second) - 1;
    ans[2] = (p[n - 2].second - p[n - 3].second) / (ans[3] + 1);
    int x = (p[n - 1].second - p[n - 2].second) - (ans[1] + 1) * (ans[3] + 1);
    ans[4] = x / (ans[3] + 1);
    if (n > 4){
        -- ans[4];
    }
    for (int i = n - 3; i >= 2; -- i){
        x = p[i].second - p[i - 1].second;
        x -= ans[n - i - 2] * ans[n - i - 1];
        x -= ans[n - i - 1] * (ans[n - i + 1] + 1);
        ans[n - i + 2] = x / (ans[n - i + 1] + 1) - (i == 2 ? 0 : 1);
    }
    putchar('!');
    for (int i = 1; i <= n; ++ i){
        printf(" %d", ans[i]);
    }
    puts("");
    return 0;
}