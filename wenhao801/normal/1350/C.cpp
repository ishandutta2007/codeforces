#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;
#define int long long

inline int read () {
    int ret = 0, t = 1;
    char c = getchar();
    while ((c < '0' || c > '9') && c != '-') c = getchar();
    if (c == '-') t = -1, c = getchar();
    while (c >= '0' && c <= '9') ret = ret * 10 + c - '0', c = getchar();
    return ret * t;
}

struct st { int val, Min, Min2; } a[200200], tmp[200200]; int top = 0;
bool np[200200];
void genp () {
    int i, j;
    for (i = 2; i <= 200000; i++) {
        if (!np[i]) a[++top].val = i, a[top].Min = a[top].Min2 = 998244353;
        for (j = 1; j <= top; j++) {
            if (i * a[j].val > 200000) break;
            np[i * a[j].val] = true;
        }
    }
}

int n;
int A[200200];
int qpow (int x, int y) {
    int ret = 1;
    while (y) {
        if (y & 1) ret = ret * x;
        x = x * x; y >>= 1; 
    }return ret;
}

signed main () {
    genp(); n = read();
    int i, j;
    for (i = 1; i <= n; i++) A[i] = read();
    for (i = 1; i <= n; i++) {
        int top2 = 0;
        for (j = 1; j <= top; j++) {
            int k = 0;
            while (A[i] % a[j].val == 0) k++, A[i] /= a[j].val;
            if (k <= a[j].Min) a[j].Min2 = a[j].Min, a[j].Min = k;
            else if (k < a[j].Min2) a[j].Min2 = k;
            if (a[j].Min + a[j].Min2 > 0)
            tmp[++top2] = a[j];
        } 
        
        top = top2;
        for (j = 1; j <= top2; j++) a[j] = tmp[j];  
    }
    int ans = 1;
    for (i = 1; i <= top; i++) ans *= qpow(a[i].val, max(a[i].Min, a[i].Min2)); cout << ans;
    return 0;
}