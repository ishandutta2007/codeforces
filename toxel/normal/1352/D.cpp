#include <bits/stdc++.h>

const int N = 100010;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    int suml = a[0], sumr = 0, move = 1;
    int prev = a[0];
    for (int i = 1, j = n - 1; i <= j; ){
        int sum = 0;
        ++ move;
        while (j >= i && sum < prev + 1){
            sum += a[j --];
        }
        sumr += sum;
        prev = sum;
        if (i > j){
            break;
        }
        sum = 0;
        ++ move;
        while (i <= j && sum < prev + 1){
            sum += a[i ++];
        }
        suml += sum;
        prev = sum;
    }
    printf("%d %d %d\n", move, suml, sumr);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
}