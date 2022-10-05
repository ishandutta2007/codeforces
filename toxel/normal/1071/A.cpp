#include<bits/stdc++.h>

int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    int sit = 0;
    for (int i = 0; ; ++ i){
        if (1ll * i * (i + 1) / 2 > a + b){
            sit = i - 1;
            break;
        }
    }
    std::vector <int> ans1, ans2;
    for (int i = sit; i >= 1; -- i){
        if (a >= i){
            a -= i;
            ans1.push_back(i);
        }
        else{
            ans2.push_back(i);
        }
    }
    int sz1 = ans1.size();
    int sz2 = ans2.size();
    printf("%d\n", sz1);
    for (int i = 0; i < sz1; ++ i){
        printf("%d%c", ans1[i], " \n"[i == sz1 - 1]);
    }
    printf("%d\n", sz2);
    for (int i = 0; i < sz2; ++ i){
        printf("%d%c", ans2[i], " \n"[i == sz2 - 1]);
    }
    return 0;
}