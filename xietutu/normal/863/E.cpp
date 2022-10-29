#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
struct seg {
    int l, r, no;
} a[maxn];
int n, l[maxn], r[maxn], R[maxn], L[maxn];
bool cmp1(const seg& lhs, const seg& rhs) {
    return lhs.l < rhs.l || (lhs.l == rhs.l && lhs.r > rhs.r);
}
bool cmp2(const seg& lhs, const seg& rhs) {
    return lhs.r > rhs.r || (lhs.r == rhs.r && lhs.l < rhs.l);
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d%d", l + i, r + i);
        a[i] = (seg){l[i], r[i], i};
    }
    
    
    sort(a + 1, a + n + 1, cmp1);
    int last = -1;
    for (int i = 1; i <= n; ++i) {
        R[a[i].no] = last;
        last = max(last, a[i].r);    
    }
    
    sort(a + 1, a + n + 1, cmp2);
    last = a[1].r + 1;
    for (int i = 1; i <= n; ++i) {
        L[a[i].no] = last;
        last = min(last, a[i].l);
    }     
    
    bool flag = false;
    for (int i = 1; i <= n; ++i)
        if (R[i] >= r[i] || (R[i] >= l[i] && R[i] + 1 >= L[i])) {
            flag = true;
            printf("%d\n", i);   
            break;
        }
    if (!flag) printf("-1");     
}