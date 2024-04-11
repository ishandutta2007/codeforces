#include<bits/stdc++.h>

const int N = 1000010;
const int BIT = 20;
const int M = 10000010;
typedef std::pair <int, int> pii;

int st1[N][BIT], st2[N][BIT];
int bit[1 << BIT];
int v[N], c[N], ans[N];
int cnt[M];
double fac[N];

pii query(int l, int r){
    int x = bit[r - l + 1];
    int vval = std::max(st1[l][x], st1[r - (1 << x) + 1][x]);
    int cval = std::min(st2[l][x], st2[r - (1 << x) + 1][x]);
    return {100 * vval, cval};
}

int main(){
    for (int i = 1; i < N; ++ i){
        fac[i] = fac[i - 1] + std::log(i);
    }
    for (int i = 2; i < 1 << BIT; ++ i){
        bit[i] = bit[i >> 1] + 1;
    }
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &v[i]);
        st1[i][0] = v[i];
    }
    for (int i = 0; i < n; ++ i){
        scanf("%d", &c[i]);
        st2[i][0] = c[i];
    }
    for (int j = 1; j < BIT; ++ j){
        for (int i = 0; i < n; ++ i){
            int sit = i + (1 << (j - 1));
            if (sit >= N) break;
            st1[i][j] = std::max(st1[i][j - 1], st1[sit][j - 1]);
            st2[i][j] = std::min(st2[i][j - 1], st2[sit][j - 1]);
        }
    }
    for (int i = 0; i < n; ++ i){
        int left = i, right = n - 1;
        while (left < right){
            int mid = (left + right + 1) >> 1;
            pii p = query(i, mid);
            if (p.first <= p.second){
                left = mid;
            }
            else{
                right = mid - 1;
            }
        }
        pii p = query(i, left);
        ans[i] = std::min(p.first, p.second);
        if (left < n - 1){
            p = query(i, left + 1);
            ans[i] = std::max(ans[i], std::min(p.first, p.second));
        }
        ++ cnt[ans[i]];
    }
    for (int i = M - 2; i >= 0; -- i){
        cnt[i] += cnt[i + 1];
    }
    double ret = 0;
    for (int i = 0; i < M - 1; ++ i){
        int u = cnt[i];
        double prob1 = u >= k ? std::exp(fac[u] + fac[n - k] - fac[u - k] - fac[n]) : 0;
        u = cnt[i + 1];
        double prob2 = u >= k ? std::exp(fac[u] + fac[n - k] - fac[u - k] - fac[n]) : 0;
        prob1 -= prob2;
        ret += i * prob1;
    }
    printf("%.15f\n", ret);
    return 0;
}