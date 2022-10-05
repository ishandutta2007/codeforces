#include <bits/stdc++.h>

const int N = 100010;

int n;
int a[N];

int ask(int x){
    if (x < 1 || x > n){
        return 0;
    }
    if (a[x]){
        return a[x];
    }
    printf("? %d\n", x);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    a[x] = ret;
    return ret;
}

bool check(int x){
    return a[x] < a[x - 1] && a[x] < a[x + 1];
}

int main(){
    scanf("%d", &n);
    if (n == 1){
        puts("! 1");
        return 0;
    }
    a[0] = a[n + 1] = INT_MAX;
    int left = 1, right = n;
    while (left < right){
        int mid = (left + right) / 2;
        ask(mid), ask(mid + 1);
        if (a[mid] < a[mid + 1]){
            right = mid;
        }
        else{
            left = mid + 1;
        }
    }
    printf("! %d\n", left);
    return 0;
}