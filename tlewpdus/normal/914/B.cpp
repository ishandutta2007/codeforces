#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

int chk[100100];

int main() {
    int n;
    int i;
    scanf("%d",&n);
    for (i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        chk[a]++;
    }
    bool f = 0;
    for (i=0;i<=100000;i++) if (chk[i]%2) f = 1;
    if (f) printf("Conan\n");
    else printf("Agasa\n");

    return 0;
}