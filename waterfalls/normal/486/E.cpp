#include <cstdio>
#include <algorithm>

using namespace std;

int n,maxLen;
int a[100000];
int len[100000];
int best[100001];
int works[100001];
int numWork[100001];
int doesWork[100000];

int main() {
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    maxLen = 0;
    best[0] = -1;
    for (int i=1;i<n;i++) best[i] = 1000000;
    for (int i=0;i<n;i++) {
        int where = lower_bound(best,best+maxLen+1,a[i])-best;
        maxLen = max(maxLen,where);
        len[i] = where;
        best[where] = min(best[where],a[i]);
    }
    for (int i=n-1;i>=0;i--) {
        if (len[i]==maxLen || works[len[i]+1]>a[i]) {
            doesWork[i] = 1;
            works[len[i]] = max(works[len[i]],a[i]);
            numWork[len[i]]+=1;
        }
    }
    for (int i=0;i<n;i++) {
        if (!doesWork[i]) printf("1");
        else if (numWork[len[i]]>1) printf("2");
        else printf("3");
    }
    printf("\n");

    return 0;
}