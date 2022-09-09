#include <bits/stdc++.h>
#define MAXN 500005

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

const int INF = 987654321;
int N,SA[MAXN],lcp[MAXN];
char S[MAXN];
bool D[2][MAXN];
int ans;
int nam[MAXN];
int las[MAXN];

void SuffixArray() {
    int i,j,k;
    int m = 26;
    vector <int> cnt(max(N,m)+1,0),x(N+1,0),y(N+1,0);
    for (i=1;i<=N;i++) cnt[x[i] = S[i]-'a'+1]++;
    for (i=1;i<=m;i++) cnt[i] += cnt[i-1];
    for (i=N;i;i--) SA[cnt[x[i]]--] = i;
    for (int len=1,p=1;p<N;len<<=1,m=p){
        for (p=0,i=N-len;++i<=N;) y[++p] = i;
        for (i=1;i<=N;i++) if (SA[i] > len) y[++p] = SA[i]-len;
        for (i=0;i<=m;i++) cnt[i] = 0;
        for (i=1;i<=N;i++) cnt[x[y[i]]]++;
        for (i=1;i<=m;i++) cnt[i] += cnt[i-1];
        for (i=N;i;i--) SA[cnt[x[y[i]]]--] = y[i];
        swap(x,y); p = 1; x[SA[1]] = 1;
        for (i=1;i<N;i++)
            x[SA[i+1]] = SA[i]+len <= N && SA[i+1]+len <= N && y[SA[i]] == y[SA[i+1]] && y[SA[i]+len] == y[SA[i+1]+len] ? p : ++p;
    }
}

void LCP() {
    int i,j,k=0;
    vector <int> rnk(N+1,0);
    for (i=1;i<=N;i++) rnk[SA[i]] = i;
    for (i=1;i<=N;lcp[rnk[i++]]=k)
        for (k?k--:0,j=SA[rnk[i]-1];S[i+k]==S[j+k];k++);
}

int main() {
    int i, j;
    scanf("%d",&N);
    scanf("%s",S+1);
    SuffixArray();
    LCP();
    D[0][0] = D[1][0] = 0;
    for (j=1;j<=N;j++) D[1][j] = 1;
    ans=1;
    for (i=2;i<=1000;i++) {
        int p = 1, q = 1;
        for (j=1;j<=N;j++) las[j] = 0;
        for (j=1;j<=N;j++) {
            if (j==N||lcp[j+1]<i-1) {
                for (;p<=j;p++) nam[SA[p]] = q;
                q++;
            }
        }
        int t = i%2;
        for (j=N;j>N-i;j--) D[t][j] = 0;
        bool good = 0;
        for (j=N-i+1;j>0;j--) {
            D[t][j] = D[1-t][las[nam[j]]]||D[1-t][las[nam[j+1]]];
            if (D[t][j]) good = 1;
            las[nam[j+i-1]]=j+i-1;
        }
        if (!good) {
            printf("%d\n",i-1);
            return 0;
        }
    }
    printf("1000\n");

    return 0;
}