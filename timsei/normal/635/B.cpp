#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;

const int N = 400007;

int cnt1 , cnt2, a[N] , b[N] , n;

int p1 , p2 , aa[N]  , bb[N];

int main() {
    scanf("%d",&n);
    for(int i = 1;i <= n;i ++) scanf("%d",&a[i]);
    for(int i = 1;i <= n;i ++) scanf("%d",&b[i]);
    cnt1 = cnt2 = 0;
    for(int i = 1;i <= n;i ++) {
        if(!a[i]) cnt1 ++;
        if(!b[i]) cnt2 ++;
    }
    if(cnt1 != cnt2) {
        puts("NO"); return 0;
    }
    for(int i = 1;i <= n;i ++) {
        if(a[i]) aa[++p1] = a[i];
        if(b[i]) bb[++p2] = b[i];
    }
    n = p1;
    for(int i = 1;i <= n;i ++) aa[n + i] = aa[i];
    int it = -1;
    for(int i = 1;i <= n;i ++) {
        if(aa[i] == bb[1]) {
            it = i;break;
        }
    }
    if(it == -1) {
        puts("NO"); return 0;
    }
    int ppp = 1;
    bool flag = 0;
    for(int i = it;i <= n + it - 1; i ++) {
        if(aa[i] != bb[ppp++]) {
            flag = 1;break;
        }
    }
    if(!flag) puts("YES");else puts("NO");
}