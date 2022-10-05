#include<bits/stdc++.h>

int main(){
    std::vector <int> ans;
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= 500000; ++ i){
        int cnt = 0, x = i;
        while (x){
            cnt += x / 5;
            x /= 5;
        }
        if (cnt == m){
            ans.push_back(i);
        }
    }
    printf("%d\n", (int) ans.size());
    for (int i = 0, sz = ans.size(); i < sz; ++ i){
        printf("%d%c", ans[i], " \n"[i == sz - 1]);
    }
    return 0;
}