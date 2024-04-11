#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int ans = 0;
    for (int i=0;i<n;i++) {
        int a,b,c,d;
        scanf("%d%d%d%d",&a,&b,&c,&d);
        ans+=(c-a+1)*(d-b+1);
    }
    printf("%d\n",ans);

    return 0;
}