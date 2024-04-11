#include <bits/stdc++.h>

const int N = 200010;

char s[N];
char a[N], b[N];

void solve(){
    int n;
    scanf("%d%s", &n, s);
    std::vector <int> one, zero;
    for (int i = 0; i < n; ++ i){
        (s[i] == '1' ? one : zero).emplace_back(i);
    }
    if (int(one.size()) % 2 == 1){
        puts("NO");
        return;
    }
    int sz = one.size();
    for (int i = 0; i < sz; ++ i){
        a[one[i]] = b[one[i]] = i < sz / 2 ? '(' : ')';
    }
    sz = zero.size();
    for (int i = 0; i < sz; i += 2){
        a[zero[i]] = '(';
        a[zero[i + 1]] = ')';
        b[zero[i]] = ')';
        b[zero[i + 1]] = '(';
    }
    int pre = 0;
    for (int i = 0; i < n; ++ i){
        pre += a[i] == '(' ? 1 : -1;
        if (pre < 0){
            puts("NO");
            return;
        }
    }
    pre = 0;
    for (int i = 0; i < n; ++ i){
        pre += b[i] == '(' ? 1 : -1;
        if (pre < 0){
            puts("NO");
            return;
        }
    }
    a[n] = b[n] = '\0';
    puts("YES");
    puts(a);
    puts(b);
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}