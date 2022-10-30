#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int n,m;
bool on[300013];

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) {
        char c;
        scanf(" %c",&c);
        on[i] = (c=='.');
    }
    int ans = 0;
    for (int i=0;i<n;i++) ans+=(on[i] && i && on[i-1]);
    for (int i=0;i<m;i++) {
        int x;
        char c;
        scanf("%d %c",&x,&c);
        x-=1;
        c = (c=='.');
        if (on[x]!=c) {
            if (c) {
                ans+=(x && on[x-1]);
                ans+=(on[x+1]);
            } else {
                ans-=(x && on[x-1]);
                ans-=(on[x+1]);
            }
        }
        on[x] = c;
        printf("%d\n",ans);
    }

    return 0;
}