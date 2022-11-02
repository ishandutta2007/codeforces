#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n;

int main() {
    scanf("%d",&n);
    int a = 0;
    int c = 0;
    int t = 0;
    int g = 0;
    for (int i=0;i<n;i++) {
        char ch;
        scanf(" %c",&ch);
        if (ch=='A') a+=1;
        if (ch=='C') c+=1;
        if (ch=='T') t+=1;
        if (ch=='G') g+=1;
    }
    int most = max(max(a,c),max(t,g));
    int num = 0;
    if (a==most) num+=1;
    if (c==most) num+=1;
    if (t==most) num+=1;
    if (g==most) num+=1;
    int ans = 1;
    int MOD = 1000000007;
    for (int i=0;i<n;i++) ans = ((long long) ans*num)%MOD;
    printf("%d\n",ans);

    return 0;
}