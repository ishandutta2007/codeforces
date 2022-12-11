#include<bits/stdc++.h>

const int N = 1010;

int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
    }
    std::sort(a, a + n);
    printf("%d\n", a[n - 1] - a[0] - (n - 1));
    return 0;
}