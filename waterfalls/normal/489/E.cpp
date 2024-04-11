#include <cstdio>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

int n,l;
int len[1001];
int pict[1001];
double dist[1001][1001];
double dp[1001];
int next[1000];

bool check(double K) {
    for (int i=0;i<=n;i++) for (int j=i+1;j<=n;j++) dist[i][j] = sqrt(abs(len[j]-len[i]-l))-K*pict[j];
    dp[n] = 0;
    for (int i=n-1;i>=0;i--) {
        dp[i] = 1000000000;
        for (int j=i+1;j<=n;j++) if (dp[i]>dist[i][j]+dp[j]) dp[i] = dist[i][j]+dp[j], next[i] = j;
    }
    return dp[0]<0;
}

int main() {
    scanf("%d%d",&n,&l);
    for (int i=1;i<=n;i++) scanf("%d%d",&len[i],&pict[i]);
    len[0] = 0;
    pict[0] = 0;
    double low = 0;
    double high = 10000;
    while (high-low>1e-11) {
        if (check((high+low)/2)) high = (high+low)/2;
        else low = (high+low)/2;
    }
    int where = 0;
    while (where<n) {
        where = next[where];
        printf("%d ",where);
    }
    printf("\n");

    return 0;
}