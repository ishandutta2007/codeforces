#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n,k;
int p[30];
double dp[201][30][30];

int two(int a, int b) { return (b-a+1)*(b-a)/2; }

int main() {
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&p[i]);
    for (int i=0;i<n;i++) for (int j=i+1;j<n;j++) for (int a=i;a<=j;a++) for (int b=a+1;b<=j;b++) dp[0][i][j]+=(p[a]>p[b]);
    double indivProb = 1./(n*(n+1)/2);
    for (int r=1;r<=k;r++) {
        for (int a=0;a<n;a++) {
            for (int b=a;b<n;b++) {
                for (int i=0;i<n;i++) {
                    for (int j=i+1;j<n;j++) {
                        if (i<=a && b<=j) dp[r][i][j]+=indivProb*(dp[r-1][i][j]-dp[r-1][a][b]+two(a,b)-dp[r-1][a][b]);
                        else if (a<=i && j<=b) dp[r][i][j]+=indivProb*(two(i,j)-dp[r-1][b+a-j][b+a-i]);
                        else if (b<i || j<a) dp[r][i][j]+=indivProb*dp[r-1][i][j];
                        else if (a>i && b>j) dp[r][i][j]+=indivProb*(dp[r-1][i][b]-dp[r-1][i][b-j+a-1]+dp[r-1][i][a-1]-dp[r-1][a][b]+dp[r-1][a][b-j+a-1]+two(a,j)-dp[r-1][b-j+a][b]);
                        else if (b<j && a<i) dp[r][i][j]+=indivProb*(dp[r-1][a][j]-dp[r-1][b-i+a+1][j]+dp[r-1][b+1][j]-dp[r-1][a][b]+dp[r-1][b-i+a+1][b]+two(i,b)-dp[r-1][a][b-i+a]);
                    }
                }
            }
        }
    }
    printf("%1.12f\n",dp[k][0][n-1]);

    return 0;
}