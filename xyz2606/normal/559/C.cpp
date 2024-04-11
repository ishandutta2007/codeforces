#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N(222222), modulo(1e9 + 7);
int inverse(int x) {
    int n(modulo - 2), res(1);
    while(n) {
        if(n & 1) {
            res = (long long)res * x % modulo;
        }
        n /= 2;
        x = (long long)x * x % modulo;
    }
    return res;
}
int fac[N], inv[N];
int calc(int x, int y) {
    //printf("calc %d %d %d %d %d\n", x, y, fac[x + y], inv[x], inv[y]);
    return (long long)fac[x + y] * inv[x] % modulo * inv[y] % modulo;
}
int main() {
    fac[0] = 1;
    inv[0] = 1;
    for(int i(1); i < N; i++) {
        fac[i] = (long long)fac[i - 1] * i % modulo;
        inv[i] = inverse(fac[i]);
    //  if(i <= 10) printf("%d %d %d\n", fac[i], inv[i], (int)((long long)fac[i] * inv[i] % modulo));
    }
    int h, w;
    int n;
    scanf("%d%d%d", &h, &w, &n);
    vector<pair<int, int> > vec;
    for(int i(0); i < n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        vec.push_back(make_pair(x, y));
    }
    vector<int> dp;
    sort(vec.begin(), vec.end());
    vec.push_back(make_pair(h, w));
    for(int i(0); i <= n; i++) {
        dp.push_back(calc(vec[i].first - 1, vec[i].second - 1));
            //printf("%d\n", dp.back());
        for(int j(0); j < i; j++) {
            if(vec[j].first <= vec[i].first && vec[j].second <= vec[i].second) {
                dp.back() = (dp.back() - (long long)dp[j] * calc(vec[i].first - vec[j].first, vec[i].second - vec[j].second)) % modulo;
            }
        }
    //  printf("%d\n", dp.back());
    }
    printf("%d\n", (dp.back() + modulo) % modulo);
}