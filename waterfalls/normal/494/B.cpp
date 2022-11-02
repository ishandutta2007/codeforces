#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char s[100013];
char t[100013];
char comb[200013];
int Z[200013];
int found[200013];

int main() {
    scanf(" %s %s",&s,&t);
    int lenS = strlen(s);
    int lenT = strlen(t);
    sscanf(t,"%s",&comb);
    comb[lenT] = '#';
    for (int i=0;i<lenS;i++) comb[i+lenT+1] = s[i];
    int len = lenS+lenT+1;
    int L = 0;
    int R = 0;
    for (int i=1;i<len;i++) {
        if (i>R) {
            L = i;
            R = i;
            while (comb[R]==comb[R-i]) R+=1;
            R-=1;
            Z[i] = R-L+1;
        } else {
            int k = i-L;
            if (Z[k]>=R-i+1) {
                L = i;
                while (comb[R]==comb[R-i]) R+=1;
                R-=1;
                Z[i] = R-L+1;
            } else Z[i] = Z[k];
        }
    }
    vector<int> occurs;
    for (int i=lenT+1;i<len;i++) {
        if (Z[i]==lenT) occurs.push_back(i-lenT-1);
        if (Z[i]==lenT) found[i-lenT-1] = 1;
        else found[i-lenT-1] = 0;
    }
    if (occurs.size()==0) {
        printf("0");
        return 0;
    }
    occurs.push_back(lenS);
    int next[lenS];
    for (int i=0;i<lenS;i++) next[i] = occurs[lower_bound(occurs.begin(),occurs.end(),i+1)-occurs.begin()];
    int MOD = 1000000007;
    int dp[lenS+1];
    int sums[lenS+1];
    int sumSums[lenS+1];
    dp[lenS] = 1;
    sums[lenS] = 1;
    sumSums[lenS] = 1;
    for (int i=lenS-1;i>=0;i--) {
        if (found[i]) dp[i] = sumSums[i+lenT];
        else {
            if (next[i]==lenS) dp[i] = 0;
            else dp[i] = dp[next[i]];
        }
        sums[i] = (dp[i]+sums[i+1])%MOD;
        sumSums[i] = (sums[i]+sumSums[i+1])%MOD;
    }
    printf("%d\n",(sums[0]+MOD-1)%MOD);

    return 0;
}