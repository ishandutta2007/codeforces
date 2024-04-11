#include<bits/stdc++.h>

const int N = 400010;
const int moder = (int) 1e9 + 7;

char s[N];
bool type[N];
int a[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%s%d", s, &a[i]);
        type[i] = s[1] == 'C';
    }
    std::set <int> set;
    int ans = 1;
    int low = 0, high = INT_MAX;
    for (int i = 0, j = 0; i < n; i = j + 1, j = i){
        while (j < n && !type[j]){
            ++ j;
        }
        if (j < n){
            if (a[j] < low || a[j] > high){
                puts("0");
                return 0;
            }
            if (!set.count(a[j])){
                ans = 2 * ans % moder;
            }
            for (int k = i; k < j; ++ k){
                set.insert(a[k]);
            }
            set.erase(a[j]);
            auto u = set.lower_bound(a[j]);
            high = u == set.end() ? INT_MAX : *u;
            if (u == set.begin()){
                low = 0;
            }
            else{
                -- u;
                low = *u;
            }
            continue;
        }
        int cnt = 0;
        for (int k = i; k < j; ++ k){
            if (a[k] > low && a[k] < high){
                ++ cnt;
            }
        }
        ans = 1ll * ans * (cnt + 1) % moder;
    }
    printf("%d\n", ans);
    return 0;
}