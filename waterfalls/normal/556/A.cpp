#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    int ans = 0;
    for (int i=0;i<n;i++) {
        char c;
        scanf(" %c",&c);
        if (c=='0') ans-=1;
        else ans+=1;
    }
    printf("%d\n",ans>0 ? ans : -ans);

    return 0;
}