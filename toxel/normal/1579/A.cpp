#include <bits/stdc++.h>

void solve(){
    std::string str;
    std::cin >> str;
    int cnt[3] = {};
    for (auto ch : str){
        ++ cnt[ch - 'A'];
    }
    puts(cnt[1] == cnt[0] + cnt[2] ? "YES" : "NO");
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}