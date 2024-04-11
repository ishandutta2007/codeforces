#include <cstdio>
#include <algorithm>

using namespace std;

long long m;
long long h1,a1,x1,y1;
long long h2,a2,x2,y2;
int one[1000013];
int two[1000013];

int main() {
    scanf("%lld",&m);
    scanf("%lld%lld%lld%lld",&h1,&a1,&x1,&y1);
    scanf("%lld%lld%lld%lld",&h2,&a2,&x2,&y2);
    long long tmp1 = h1;
    long long tmp2 = h2;
    one[h1] = 1;    
    int cyc1;
    int t1 = -1;
    for (int i=2;i<=m+2;i++) {
        h1 = (x1*h1+y1)%m;
        if (one[h1]) {
            cyc1 = i-one[h1];
            break;
        }
        if (h1==a1) t1 = i-1;
        one[h1] = i;
    }
    int found1 = 0;
    for (int i=0;i<cyc1;i++) {
        h1 = (x1*h1+y1)%m;
        if (h1==a1) found1 = 1;
    }
    two[h2] = 1;
    int cyc2;
    int t2 = -1;
    for (int i=2;i<=m+2;i++) {
        h2 = (x2*h2+y2)%m;
        if (two[h2]) {
            cyc2 = i-two[h2];
            break;
        }
        if (h2==a2) t2 = i-1;
        two[h2] = i;
    }
    int found2 = 0;
    for (int i=0;i<cyc2;i++) {
        h2 = (x2*h2+y2)%m;
        if (h2==a2) found2 = 1;
    }
    if (t1==-1 || t2==-1) printf("-1\n");
    else if (!found1 || !found2) {
        int found = 1e9;
        for (int i=0;i<m;i++) {
            tmp1 = (x1*tmp1+y1)%m;
            tmp2 = (x2*tmp2+y2)%m;
            if (tmp1==a1 && tmp2==a2) found = min(found,i+1);
        }
        if (found!=1e9) printf("%d\n",found);
        else printf("-1\n");
    } else {
        long long ans = -1;
        for (int i=0;i<cyc2;i++) {
            long long cur = (t1%cyc1)+((long long) i*cyc1);
            if ((cur%cyc2)==(t2%cyc2)) {
                ans = cur;
                break;
            }
        }
        if (ans==-1) printf("-1\n");
        else {
            while (ans<t1 || ans<t2) ans+=(long long) cyc1*cyc2;
            printf("%lld\n",ans);
        }
    }
    
    return 0;
}