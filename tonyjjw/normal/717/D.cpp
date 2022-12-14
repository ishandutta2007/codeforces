//*
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <unordered_map>
#include <functional>
#define MOD 1000000007
#define MAX 0x3f3f3f3f
#define MAX2 0x3f3f3f3f3f3f3f3fll
#define ERR 1e-10
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#pragma warning(disable:4996)
using namespace std;

typedef double db;
typedef long long ll;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

class Matrix {
public:
    db v[128][128];
    Matrix() {
        for(int i = 0; i < 128; i++) for(int j = 0; j < 128; j++) v[i][j] = 0;
    }
    Matrix operator * (Matrix l) {
        Matrix rv = Matrix();
        for(int i = 0; i < 128; i++) {
            for(int j = 0; j < 128; j++) {
                for(int k = 0; k < 128; k++) rv.v[i][j] += v[i][k] * l.v[k][j];
            }
        }
        return rv;
    }
};

db P[105];
int main() {
    int N, X, i, j;
    scanf("%d %d", &N, &X);
    for(i = 0; i <= X; i++) scanf("%lf", &P[i]);

    Matrix mul = Matrix();
    for(i = 0; i < 128; i++) {
        for(j = 0; j <= X; j++) {
            int t = i^j;
            mul.v[t][i] += P[j];
        }
    }
    Matrix ans = Matrix();
    for(i = 0; i < 128; i++) ans.v[i][i] = 1;

    while(N) {
        if(N%2) ans = ans*mul;
        mul = mul*mul;
        N /= 2;
    }
    printf("%.20lf\n", 1 - ans.v[0][0]);
    return 0;
}