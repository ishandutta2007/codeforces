#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef long long ll;

int N,M,K;
ll A[100001];
int L[100001],R[100001],D[100001];
ll dp[100001];
int accum[350][100001];
ll dp2[100001];

int main() {
    scanf("%d %d %d", &N, &M, &K);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    for (int i = 0; i < M; ++i) {
        scanf("%d %d %d", L + i, R + i, D + i);
        --L[i],--R[i];
    }

    for (int i = 0; i < K; ++i) {
        int X,Y;
        scanf("%d %d", &X, &Y);
        --X,--Y;
        dp2[X]++;
        dp2[Y+1]--;
    }
    for (int i = 0; i < M; ++i) {
        dp2[i+1] += dp2[i];
        dp[L[i]] += D[i] * dp2[i];
        dp[R[i]+1] -= D[i] * dp2[i];
    }

    for (int i = 0; i < N; ++i) {
        A[i] += dp[i];
        dp[i+1] += dp[i];
        cout << A[i];
        if (i != N-1) printf(" ");
    }
    printf("\n");

}