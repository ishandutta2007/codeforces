#include <bits/stdc++.h>

using namespace std;

int n, p, l, r;

int main() {

    scanf("%d%d%d%d",&n,&p,&l,&r);
    if (p>r) {
        int tl = l;
        l = n+1-r;
        r = n+1-tl;
        p = n+1-p;
    }
    if (p<l) {
        if (r==n) printf("%d\n",l-p+1);
        else printf("%d\n",l-p+1+r-l+1);
    }
    else {
        if (l==1&&r==n) printf("0\n");
        else if (l==1) printf("%d\n",r-p+1);
        else if (r==n) printf("%d\n",p-l+1);
        else printf("%d\n",min(p-l+1+r-l+1,r-p+1+r-l+1));
    }

    return 0;
}