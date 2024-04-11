#include <bits/stdc++.h>

const int N = 100010;

int p[N];
int left[N], right[N];
int leftm[N], rightm[N];
int premax[N], sufmax[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++ i){
        scanf("%d", &p[i]);
    }
    for (int i = 2; i <= n; ++ i){
        if (p[i - 1] < p[i]){
            left[i] = left[i - 1] + 1;
        }
        else{
            left[i] = 0;
        }
    }
    for (int i = 2; i <= n; ++ i){
        if (p[i - 1] < p[i]){
            leftm[i] = 0;
        }
        else{
            leftm[i] = leftm[i - 1] + 1;
        }
    }
    for (int i = n - 1; i >= 1; -- i){
        if (p[i] > p[i + 1]){
            right[i] = right[i + 1] + 1;
        }
        else{
            right[i] = 0;
        }
    }
    for (int i = n - 1; i >= 1; -- i){
        if (p[i] > p[i + 1]){
            rightm[i] = 0;
        }
        else{
            rightm[i] = rightm[i + 1] + 1;
        }
    }
    for (int i = 1; i <= n; ++ i){
        premax[i] = std::max(premax[i - 1], leftm[i]);
        premax[i] = std::max(premax[i], rightm[i]);
    }
    for (int i = n; i >= 1; -- i){
        sufmax[i] = std::max(sufmax[i + 1], leftm[i]);
        sufmax[i] = std::max(sufmax[i], rightm[i]);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++ i){
        if (left[i] == 0 || right[i] == 0){
            continue;
        }
        if (std::max(left[i], right[i]) - std::min(left[i], right[i]) >= 1){
            continue;
        }
        if (left[i] % 2 == 1){
            continue;
        }
        int ll = i - left[i], rr = i + right[i];
        if (leftm[ll] >= left[i] || rightm[rr] >= left[i]){
            continue;
        }
        if (premax[ll - 1] >= left[i] || sufmax[rr + 1] >= left[i]){
            continue;
        }
        ++ ans;
    }
    printf("%d\n", ans);
    return 0;
}