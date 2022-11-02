#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n,m,len;
char s[1000013];
int Z[1000013];
int y[1000013];
int sums[1000013];

const int MOD = 1000000007;

int main() {
    scanf("%d%d %s",&n,&m,&s);
    for (int i=0;i<m;i++) scanf("%d",&y[i]);
    for (int i=0;i<m;i++) y[i]-=1;
    len = strlen(s);
    int L = 0;
    int R = 0;
    for (int i=1;i<len;i++) {
        if (i>R) {
            L = i;
            R = i;
            while (s[R]==s[R-i]) R+=1;
            R-=1;
            Z[i] = R-L+1;
        } else {
            int k = i-L;
            if (Z[k]>=R-i+1) {
                L = i;
                while (s[R]==s[R-i]) R+=1;
                R-=1;
                Z[i] = R-L+1;
            } else Z[i] = Z[k];
        }
    }
    int ok = 1;
    for (int i=1;i<m;i++) {
        int prev = y[i-1];
        int cur = y[i];
        int diff = cur-prev;
        if (Z[diff]<len-diff) ok = 0;
    }
    if (!ok) printf("0\n");
    else {
        for (int i=0;i<m;i++) sums[y[i]]+=1,sums[y[i]+len]-=1;
        int ans = 1;
        for (int i=0;i<n;i++) {
            if (sums[i]==0) ans = ((long long) ans*26)%MOD;
            sums[i+1]+=sums[i];
        }
        printf("%d\n",ans);
    }

    return 0;
}