#include <bits/stdc++.h>

using namespace std;

int n, a, b, s = -1, t;

void print(int s, int e) {
    int i;
    for (i=s;i<e-1;i++) printf("%d ",i+1);
    printf("%d ",s);
}

int main() {
    int i;

    scanf("%d%d%d",&n,&a,&b);
    for (i=0;i<=n;i+=a) {
        if ((n-i)%b==0) {
            s = i/a;
            t = (n-i)/b;
        }
    }
    if (s<0) {
        printf("-1\n");
        return 0;
    }
    int p = 1;
    for (i=0;i<s;i++) {
        print(p,p+a);
        p+=a;
    }
    for (i=0;i<t;i++) {
        print(p,p+b);
        p+=b;
    }

    return 0;
}