#include <bits/stdc++.h>

const int N = 100010;
using ll = long long;

int p[N];
char s[N];
int cnt[N];

int main(){
    /*int n = 2;
    for (int i = 1; i < n; ++ i){
        p[i] = i;
    }
    std::set <int> set;
    do{
        int vis = 0;
        int state = 0;
        for (int i = 1; i <= n; ++ i){
            int x = p[i] - 1;
            for (int j = x; j >= 0 && !(vis >> j & 1); -- j){
                state ^= 1 << j;
            }
            vis |= 1 << x;
        }
        set.insert(state);
    }
    while (std::next_permutation(p + 1, p + n));
    for (auto u : set){
        printf("%d\n", u);
    }*/
    int n;
    ll t;
    scanf("%d%lld", &n, &t);
    scanf("%s", s);
    t -= 1 << (s[n - 1] - 'a');
    t += 1 << (s[n - 2] - 'a');
    ll sum = 0;
    for (int i = 0; i < n - 2; ++ i){
        sum += 1 << (s[i] - 'a');
        ++ cnt[s[i] - 'a'];
    }
    if ((t + sum) % 2 == 1){
        puts("No");
        return 0;
    }
    t = (t + sum) / 2;
    for (int i = 25; i >= 0; -- i){
        while (cnt[i] > 0 && t >= (1 << i)){
            t -= 1 << i;
            -- cnt[i];
        }
    }
    puts(t == 0 ? "Yes" : "No");
    return 0;
}