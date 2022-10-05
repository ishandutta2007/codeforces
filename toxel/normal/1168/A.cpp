#include <bits/stdc++.h>

const int N = 300010;

int n, m;
int a[N];

bool check(int mid){
    int now = 0;
    for (int i = 0; i < n; ++ i){
        int left = std::max(now, a[i]), right = a[i] + mid;
        if (left > right){
            return false;
        }
        if (right >= now + m){
            now = now;
        }
        else{
            now = left;
        }
    }
    return true;
}

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int left = 0, right = m;
    while (left < right){
        int mid = (left + right) >> 1;
        if (check(mid)){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    printf("%d\n", left);
    return 0;
}