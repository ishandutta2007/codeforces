#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,ans;
int lights[8192];

int dfs(int x) {
    if (x>=(1<<n)) return lights[x];
    else {
        int one = dfs(x*2);
        int two = dfs(x*2+1);
        ans+=abs(one-two);
        return max(one,two)+lights[x];
    }
}

int main() {
    scanf("%d",&n);
    for (int i=2;i<=(1<<(n+1))-1;i++) scanf("%d",&lights[i]);
    ans = 0;
    dfs(1);
    printf("%d\n",ans);

    return 0;
}