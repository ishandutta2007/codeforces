#include <bits/stdc++.h>

const int N = 200010;

int a[N], b[N];
bool inhand[N];
int n;

bool check(int mid){
    memset(inhand, 0, sizeof(inhand));
    for (int i = 0; i < n; ++ i){
        inhand[a[i]] = true;
    }
    for (int i = 0; i < mid; ++ i){
        inhand[b[i]] = true;
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++ i){
        cnt += inhand[i];
    }
    if (cnt == n){
        return true;
    }
    for (int i = 1; i <= n; ++ i){
        if (!inhand[i]){
            return false;
        }
        if (i + mid - 1 < N) {
            inhand[b[i + mid - 1]] = true;
        }
    }
    return true;
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        if (a[i]){
            inhand[a[i]] = true;
        }
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &b[i]);
    }
    int sit1 = -1;
    for (int i = 0; i < n; ++ i){
        if (b[i] == 1){
            sit1 = i;
            break;
        }
    }
    if (sit1 != -1) {
        bool flag = true;
        for (int i = sit1; i < n; ++ i){
            if (b[i] != i - sit1 + 1){
                flag = false;
                break;
            }
        }
        if (flag){
            for (int i = 0; i < sit1; ++ i){
                int x = n - sit1 + i + 1;
                if (!inhand[x]){
                    flag = false;
                    break;
                }
                inhand[b[i]] = true;
            }
        }
        if (flag){
            printf("%d\n", sit1);
            return 0;
        }
    }
    int left = 0, right = n;
    while (left < right){
        int mid = (left + right) >> 1;
        if (check(mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    printf("%d\n", left + n);
    return 0;
}