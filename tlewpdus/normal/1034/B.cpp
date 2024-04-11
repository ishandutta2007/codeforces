#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int n, m;

int main() {
    int i;

    scanf("%d%d",&n,&m);
    if (n>m) swap(n,m);
    if (n==1) {
        printf("%d\n",((m%6>0&&m%6<4)?(m/6*3):((m-1)/6*3+(m-1)%6-2))*2);
        return 0;
    }
    if (n==2) {
        if (m==2) printf("0\n");
        else if (m==3) printf("4\n");
        else if (m==7) printf("12\n");
        else printf("%d\n",2*m);
        return 0;
    }
    printf("%lld\n",1LL*n*m/2*2);

    return 0;
}