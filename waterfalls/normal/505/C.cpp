#include <cstdio>
#include <algorithm>

using namespace std;

int n,d,offset;
int gems[30002];
int dp[30002][500];

int solve(int where, int l) {
    if (dp[where][l+offset]!=-1) return dp[where][l+offset];
    int ans = 0;
    if (where+l+1<30001) ans = max(ans,solve(where+l+1,l+1));
    if (where+l<30001) ans = max(ans,solve(where+l,l));
    if (where+l-1<30001 && l>1) ans = max(ans,solve(where+l-1,l-1));
    return dp[where][l+offset] = ans+gems[where];
}

int main() {
    scanf("%d%d",&n,&d);
    for (int i=0;i<n;i++) {
        int a;
        scanf("%d",&a);
        gems[a]+=1;
    }
    offset = 250-d;
    for (int i=0;i<30002;i++) for (int j=0;j<500;j++) dp[i][j] = -1;
    printf("%d\n",solve(d,d));

    return 0;
}