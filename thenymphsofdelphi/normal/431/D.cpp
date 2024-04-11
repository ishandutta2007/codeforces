#include<bits/stdc++.h>
#define int long long
using namespace std;

#define linf 2000000000000000000
#define bit(mask, i) ((mask >> i) & 1)

const int mxbit = 63;

long long C[mxbit + 1][mxbit + 1];

int bcount(int x){
    int res = 0;
    for (; x != 0; x &= (x - 1)){
        res++;
    }
    return res;
}

int solve(int x, int k){
    int ans = (k == bcount(x));
    for (int i = mxbit; i >= 0 && k >= 0; i--){
        if (bit(x, i)){ 
            ans += C[i][k--];
        }
    }
    return ans;
}

signed main(){
    C[0][0] = 1;
    for (int i = 1; i <= mxbit; i++){
        for (int j = 0; j <= i; j++){
            C[i][j] = C[i - 1][j] + ((j) ? (C[i - 1][j - 1]) : 0);
        }
    }
    int count, k;
    scanf("%lld%lld", &count, &k);
    long long l = 1, r = linf / 2;
    while (l < r){
        int mid = l + (r - l) / 2;
        if (solve(mid * 2, k) - solve(mid, k) < count){
            l = mid + 1;
        }
        else{
            r = mid;
        }
    }
    printf("%lld\n", l);
    return 0;
}