#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
char S[5013];
short lcp[5013][5013];
int ways[5013][5013];
int sums[5013][5013];
int least[5013][5013];
int cover[5013][5013];

const int MOD = 1000000007;

bool below(int one, int two, int j) {
    int l = lcp[one][two];
    if (l>=j) return false;
    return S[one+l]<S[two+l];
}

int eval(int start) {
    int ans = 0;
    for (int i=start;i<=N;i++) {
        ans = (ans*2)%MOD;
        if (S[i]=='1') ans+=1;
    }
    return ans%MOD;
}

int main() {
    scanf(" %s",&S[1]);
    N = strlen(S+1);
    for (int i=N;i>0;i--) if (S[i]==S[N]) lcp[i][N] = 1, lcp[N][i] = 1;
    for (int i=N-1;i>0;i--) {
        for (int j=N-1;j>0;j--) {
            if (S[i]==S[j]) lcp[i][j] = 1+lcp[i+1][j+1];
        }
    }
    for (int i=0;i<=N;i++) for (int j=0;j<=N;j++) least[i][j] = 10000, cover[i][j] = 10000;
    for (int i=1;i<=N;i++) {
        for (int j=1;j<i;j++) {
            int prev = i-j;
            ways[i][j] = sums[prev][min(j,prev)];
            least[i][j] = 1+cover[prev][min(j,prev)];
            if (prev-j>=0 && below(i-j+1,prev-j+1,j)) {
                ways[i][j] = (ways[i][j]-ways[prev][j]+MOD)%MOD;
                least[i][j] = 1+cover[prev][j-1];
            }
            if (S[i-j+1]=='0') ways[i][j] = 0, least[i][j] = 10000;
            sums[i][j] = (sums[i][j-1]+ways[i][j])%MOD;
            cover[i][j] = min(cover[i][j-1],least[i][j]);
        }
        ways[i][i] = 1;
        sums[i][i] = (sums[i][i-1]+ways[i][i])%MOD;
        least[i][i] = 1;
        cover[i][i] = min(cover[i][i-1],least[i][i]);
    }
    int ans = 0;
    for (int i=1;i<=N;i++) ans = (ans+ways[N][i])%MOD;
    int best = 1000000007;
    int above = 1;
    for (int i=N;i>=0;i--) if (ways[N][i]) {
        int cur = eval(N-i+1)+least[N][i];
        if (i>25) best = cur%MOD;
        else {
            if (above) best = cur, above = 0;
            else best = min(best,cur);
        }
    }
    printf("%d\n%d\n",ans,best);

    return 0;
}