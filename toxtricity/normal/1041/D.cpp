#include<bits/stdc++.h>

const int N = 200010;

int x1[N], x2[N];
int pre[N];

int main(){
    int n, h;
    scanf("%d%d", &n, &h);
    for (int i = 0; i < n; ++ i){
        scanf("%d%d", &x1[i], &x2[i]);
        pre[i] = (i ? pre[i - 1] : 0) + x2[i] - x1[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++ i){
        int left = i, right = n - 1;
        while (left < right){
            int mid = left + right + 1 >> 1;
            if (x2[mid] - x1[i] - (pre[mid] - (i ? pre[i - 1] : 0)) >= h){
                right = mid - 1;
            }
            else{
                left = mid;
            }
        }
        ans = std::max(ans, pre[left] - (i ? pre[i - 1] : 0));
    }
    printf("%d\n", ans + h);
    return 0;
}