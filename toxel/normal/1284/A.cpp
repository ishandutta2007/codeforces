#include <bits/stdc++.h>

const int N = 30;

std::string s[N], t[N];
char tmp[N];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i){
        scanf("%s", tmp);
        s[i] = tmp;
    }
    for (int i = 0; i < m; ++ i){
        scanf("%s", tmp);
        t[i] = tmp;
    }
    int q;
    scanf("%d", &q);
    while (q --){
        int x;
        scanf("%d", &x);
        -- x;
        std::cout << s[x % n] << t[x % m] << std::endl;
    }
    return 0;
}