#include <cstdio>
#include <algorithm>
int v[1005],a,b,n;
int main() {

    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) scanf("%d",v + i);
    int left = n,l = 1,r = n;
    bool bo = true; int now;
    while (left) {
        --left;
        if (v[l] > v[r]) now = v[l++];
        else now = v[r--];
        if (bo) a += now;
        else b += now;
        bo = !bo;
    }
    printf("%d %d\n",a,b);

}