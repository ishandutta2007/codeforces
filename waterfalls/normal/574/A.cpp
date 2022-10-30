#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int n,has;
int a[113];

int main() {
    scanf("%d%d",&n,&has);
    n-=1;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int ans = 0;
    while (true) {
        sort(a,a+n,greater<int>());
        if (has>a[0]) return printf("%d\n",ans), 0;
        a[0]-=1;
        has+=1;
        ans+=1;
    }

    return 0;
}