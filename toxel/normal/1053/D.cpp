#include<bits/stdc++.h>

const int N = 2000010;
const int moder = 1e9 + 7;

std::vector <int> prime;
int cnt[N], min[N], max[N], mmax[N], mcnt[N];
bool phi[N];

int powermod(int a, int exp){
    int ret = 1;
    for ( ; exp > 0; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}

int main(){
    for (int i = 2; i < N; ++ i){
        if (!min[i]){
            min[i] = i;
            prime.push_back(i);
        }
        for (auto u : prime){
            if (i * u >= N){
                break;
            }
            min[i * u] = u;
            if (i % u == 0){
                break;
            }
        }
    }
    int n;
    scanf("%d", &n);
    for (int i = 0, p; i < n; ++ i){
        scanf("%d", &p);
        ++ cnt[p];
    }
    bool flag = false;
    for (int i = N - 1; i >= 0; -- i){
        while (cnt[i]){
            if (!max[i]){
                ++ max[i];
            }
            else{
                bool flag1 = false;
                int x = i - 1;
                while (x > 1){
                    int tmp = min[x], ccnt = 0;
                    while (x % tmp == 0){
                        x /= tmp;
                        ++ ccnt;
                    }
                    if (ccnt > max[tmp]){
                        max[tmp] = ccnt;
                        flag1 = true;
                    }
                }
                if (!flag1){
                    flag = true;
                    break;
                }
                else{
                    phi[i] = true;
                }
            }
            -- cnt[i];
        }
    }
    for (int i = 0; i < N; ++ i){
        if (phi[i]){
            int x = i - 1;
            while (x > 1){
                int tmp = min[x], ccnt = 0;
                while (x % tmp == 0){
                    x /= tmp;
                    ++ ccnt;
                }
                if (ccnt > mmax[tmp]){
                    mmax[tmp] = ccnt;
                    mcnt[tmp] = 1;
                }
                else if (ccnt == mmax[tmp]){
                    ++ mcnt[tmp];
                }
            }
        }
    }
    for (int i = 0; i < N; ++ i){
        if (phi[i]){
            bool flag1 = true;
            int x = i - 1;
            while (x > 1){
                int tmp = min[x], ccnt = 0;
                while (x % tmp == 0){
                    x /= tmp;
                    ++ ccnt;
                }
                if (mmax[tmp] == ccnt && mcnt[tmp] == 1){
                    flag1 = false;
                    break;
                }
            }
            if (flag1){
                flag = true;
                break;
            }
        }
    }
    int ans = 1;
    for (int i = 1; i < N; ++ i){
        ans = 1ll * powermod(i, max[i]) * ans % moder;
    }
    ans += flag;
    ans -= ans >= moder ? moder : 0;
    printf("%d\n", ans);
    return 0;
}