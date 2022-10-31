#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int m,t,r,w;
int visit[600];
int lit[600];

int main() {
    scanf("%d%d%d",&m,&t,&r);
    if (t<r) {
        printf("%d\n",-1);
        return 0;
    }
    for (int i=0;i<m;i++) {
        scanf("%d",&w);
        visit[w+299] = 1;
    }
    int cur = 0;
    int which = 0;
    int ans = 0;
    for (int time=0;time<600;time++) {
        if (time-t-1>=0 && lit[time-t-1]) cur-=1;
        if (visit[time]) {
            int check = time-1;
            while (cur<r) {
                if (!lit[check]) {
                    lit[check] = 1;
                    cur+=1;
                    ans+=1;
                }
                check-=1;
            }
        }
    }
    printf("%d\n",ans);
}