#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int h;
long long n;

int main() {
    scanf("%d%I64d",&h,&n);
    n-=1;
    long long ans = 0;
    long long pos = 0;
    int state = 0;
    for (int i=h;i>0;i--) {
        ans+=1;
        if ((state==0 && n>=(1LL<<(i-1))) || (state==1 && n<(1LL<<(i-1)))) {
            ans+=(1LL<<i)-1;
        } else state^=1;
        if (state==0) n-=(1LL<<(i-1));
    }
    printf("%I64d\n",ans);

    return 0;
}