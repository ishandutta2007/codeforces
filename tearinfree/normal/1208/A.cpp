#include <bits/stdc++.h>
#define fi first
#define se second
#define sz(x) ((int)(x).size())
using namespace std;
using pii = pair<int,int>;
using lli = long long;
using pli = pair<lli,int>;
using pll = pair<lli,lli>;
using pdd = pair<double,double>;

int main() {
    int test;
    scanf("%d",&test);
    while(test--) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        c%=3;
        if(c==0) printf("%d\n",a);
        else if(c==1) printf("%d\n",b);
        else printf("%d\n",a^b);
    }
    return 0;
}