#include <bits/stdc++.h>

const int N = 200010;
const int MAX = 200'000;
using ll = long long;

ll a[N], b[N], c[N], d[N];

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &a[i]);
        d[i] = a[i];
    }
    for (int i = 0; i < n; ++ i){
        scanf("%lld", &b[i]);
        c[i] = b[i];
    }
    if (n == 1){
        if (a[0] == b[0]){
            puts("SMALL\n0\n");
        }
        else{
            puts("IMPOSSIBLE");
        }
        return 0;
    }
    if (n == 2){
        ll min = 0;
        if (a[0] == b[0] && a[1] == b[1]){
        }
        else if (a[0] == b[1] && a[1] == b[0]){
        }
        else{
            if (a[0] > a[1]){
                std::swap(a[0], a[1]);
            }
            bool flag = false;
            while (true){
                if (b[0] == b[1]){
                    puts("IMPOSSIBLE");
                    return 0;
                }
                if (b[0] > b[1]){
                    std::swap(b[0], b[1]);
                }
                if (b[0] == 0){
                    break;
                }
                if (a[0] == b[0]){
                    if ((b[1] - a[1]) % a[0]){
                        break;
                    }
                    min += (b[1] - a[1]) / a[0];
                    flag = true;
                    break;
                }
                min += b[1] / b[0];
                b[1] %= b[0];
                std::swap(b[0], b[1]);
            }
            if (!flag){
                puts("IMPOSSIBLE");
                return 0;
            }
            if (min > MAX){
                printf("BIG\n%lld\n", min);
                return 0;
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        b[i] = c[i];
        a[i] = d[i];
    }
    std::vector<char> ans;
    int cnt = 0;
    while (true){
        bool flag = true;
        for (int i = 0; i < n; ++ i){
            if (a[i] != b[i]){
                flag = false;
                break;
            }
        }
        if (flag){
            break;
        }
        flag = true;
        for (int i = 0; i < n; ++ i){
            if (a[n - i - 1] != b[i]){
                flag = false;
                break;
            }
        }
        if (flag){
            ans.emplace_back('R');
            break;
        }
        flag = true;
        for (int i = 0; i < n - 1; ++ i){
            if (b[i] >= b[i + 1]){
                flag = false;
                break;
            }
        }
        if (flag){
            ++ cnt;
            ans.emplace_back('P');
            for (int i = n - 1; i > 0; -- i){
                b[i] -= b[i - 1];
                if (b[i] <= 0){
                    puts("IMPOSSIBLE");
                    return 0;
                }
            }
        }
        else{
            ans.emplace_back('R');
            std::reverse(b, b + n);
            ++ cnt;
            ans.emplace_back('P');
            for (int i = n - 1; i > 0; -- i){
                b[i] -= b[i - 1];
                if (b[i] <= 0){
                    puts("IMPOSSIBLE");
                    return 0;
                }
            }
        }
    }
    if (int(ans.size()) > MAX){
        puts("BIG");
        printf("%d\n", cnt);
        return 0;
    }
    std::reverse(ans.begin(), ans.end());
    puts("SMALL");
    printf("%d\n", int(ans.size()));
    for (auto u : ans){
        putchar(u);
    }
    puts("");
    return 0;
}