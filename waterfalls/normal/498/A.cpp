#include <cstdio>

using namespace std;

int main() {
    long long x1,y1,x2,y2,n;
    scanf("%I64d%I64d%I64d%I64d%I64d",&x1,&y1,&x2,&y2,&n);
    int ans = 0;
    for (int i=0;i<n;i++) {
        long long a,b,c;
        scanf("%I64d%I64d%I64d",&a,&b,&c);
        long long one = a*x1+b*y1+c;
        long long two = a*x2+b*y2+c;
        if ((one>0 && two<0) || (one<0 && two>0)) ans+=1;
    }
    printf("%d\n",ans);

    return 0;
}