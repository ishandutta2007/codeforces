#include <bits/stdc++.h>

const int N = 110;

int n;

int ask(int diff){
    if (diff > 0){
        printf("? ");
        for (int i = 1; i < n; ++ i){
            printf("%d ", 1);
        }
        printf("%d\n", diff + 1);
    }
    else{
        printf("? ");
        for (int i = 1; i < n; ++ i){
            printf("%d ", -diff + 1);
        }
        printf("%d\n", 1);
    }
    fflush(stdout);
    int result;
    scanf("%d", &result);
    return result;
}

int a[N];

int main(){
    scanf("%d", &n);
    for (int diff = -(n - 1); diff <= n - 1; ++ diff){
        if (diff == 0){
            continue;
        }
        int ret = ask(diff);
        if (ret){
            a[ret] = diff;
        }
    }
    int min = *std::min_element(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++ i){
        a[i] -= min - 1;
    }
    printf("!");
    for (int i = 1; i <= n; ++ i){
        printf(" %d", a[i]);
    }
    puts("");
    return 0;
}