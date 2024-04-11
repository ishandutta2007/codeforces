#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int digits = 0;
    long long t = n;
    while (t) digits+=1, t/=10;
    t = 9;
    long long ans = 0;
    for (int i=1;i<digits;i++) ans+=t*i, t*=10;
    t = 1;
    for (int i=1;i<digits;i++) t*=10;
    ans+=digits*(n-t+1);
    printf("%I64d\n",ans);

    return 0;
}