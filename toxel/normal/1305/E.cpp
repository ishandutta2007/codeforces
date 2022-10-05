#include <bits/stdc++.h>

const int N = 5010;

int ans[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    int pos = 0, sum = 0, tsum = 0;
    for (int i = 1; i <= n; ++ i){
        sum += (i - 1) / 2;
        if (sum <= m){
            tsum = sum;
            pos = i;
        }
    }
    if (sum < m){
        puts("-1");
        return 0;
    }
    for (int i = 1; i <= pos; ++ i){
        ans[i] = i;
    }
    int begin = pos + 1;
    if (m > tsum){
        int diff = m - tsum;
        ans[pos + 1] = ans[pos] + ans[pos - diff * 2];
        ++ begin;
    }
    for (int i = begin; i <= n; ++ i){
        ans[i] = int(5e8) + 1 + (i - pos - 1) * 5001;
    }
    for (int i = 1; i <= n; ++ i){
        printf("%d%c", ans[i], " \n"[i == n]);
    }
    return 0;
}