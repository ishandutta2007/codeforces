
#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using lli = long long;
using pii = pair<int,int>;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;

int n,m,k,a[100],b[100];

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        scanf("%d%d%d",&n,&m,&k);
        for(int i=0;i<m;i++) scanf("%d",a+i);
        for(int i=0;i<k;i++) scanf("%d",b+i);

        if(*max_element(a,a+m) > *max_element(b,b+k)) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}