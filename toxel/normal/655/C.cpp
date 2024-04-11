#include<bits/stdc++.h>

const int N = 100010;

int pre[N];
char s[N];

int getpre(int sit){
    if (sit < 0) return 0;
    return pre[std::min(N - 1, sit)];
}

int main(){
    int n, k;
    scanf("%d%d", &n, &k);
    scanf("%s", s);
    for (int i = 0; i < N; ++ i){
        pre[i] = (i ? pre[i - 1] : 0) + (s[i] == '0');
    }
    int ans = INT_MAX;
    for (int i = 0; i < n; ++ i){
        if (s[i] == '1') continue;
        int left = 0, right = n;
        while (left < right){
            int mid = (left + right) >> 1;
            int num = getpre(i + mid) - getpre(i) + getpre(i - 1) - getpre(i - mid - 1);
            if (num >= k){
                right = mid;
            }
            else{
                left = mid + 1;
            }
        }
        ans = std::min(ans, left);
    }
    printf("%d\n", ans);
    return 0;
}