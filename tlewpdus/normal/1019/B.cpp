#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n;

int ask(int a) {
    printf("? %d\n",a%n+1);
    fflush(stdout);
    int b;
    scanf("%d",&b);
    return b;
}

void ans(int a) {
    printf("! %d\n",a%n+1);
    fflush(stdout);
    exit(0);
}

int main() {
    scanf("%d",&n);
    if ((n/2)%2) {
        printf("! -1\n");
        fflush(stdout);
        return 0;
    }
    int a, b;
    a = ask(0);
    b = ask(n/2);
    if (a==b) ans(0);
    int s = 1, e = n/2-1;
    if (a-b>0) {
        s = n/2+1, e = n-1;
    }
    while(s<=e) {
        int m = (s+e)/2;
        int v = ask(m)-ask(m+n/2);
        if (v==0) ans(m);
        if (v<0) s = m+1;
        else e = m-1;
    }
        printf("! -1\n");
        fflush(stdout);
        return 0;

}