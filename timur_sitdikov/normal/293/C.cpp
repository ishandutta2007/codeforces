#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <vector>
#include <iostream>
#include <complex>
using namespace std;
#define pb push_back
#define mp make_pair
#define point complex <double>
#define xx real()
#define yy imag()

const int MAXN = 3000005;

long long divs[MAXN], div2[MAXN];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    long long n, v1, v2, v3, i, j, k, top = 0, tmp;
    scanf("%I64d", &n);
    if (n % 3){
        printf("0");
        return 0;
    }
    n /= 3;
    for(i = 2; i * i <= n; i++){
        if (!(n % i)){
            divs[top] = i;
            div2[top++] = n / i;
        }
    }
    if (top == 0){
        printf("0");
        return 0;
    }
    i = top - 1;
    if (divs[top - 1] == div2[top - 1]){
        i = top - 2;
    }
    for(; i >= 0; i--){
        divs[top++] = div2[i];
    }
    long long ans = 0;
    long long a, b, c;
    for(i = 0; i < top; i++){
        v1 = divs[i];
        if (v1 > 40000 || v1 * v1 * v1 > n)
            break;
        k = top - 1 - i;
        for(j = i; j < k; j++){
            if (divs[j] > 1000000000 || divs[j] * divs[j] > divs[k])
                break;
            if (divs[k] % divs[j])
                continue;
            v2 = divs[j];
            v3 = divs[k] / divs[j];
            tmp = v2 + v3 - v1;
            if (tmp & 1)
                continue;
            c = tmp / 2;
            b = v3 - c;
            a = v2 - c;
            if (a <= 0 || b <= 0 || c <= 0)
                continue;
            if (a == b && a == c){
                ans++;
            }
            else if (a == b || a == c || b == c){
                ans += 3;
            }
            else{
                ans += 6;
            }
        }
    }
    printf("%I64d", ans);
}