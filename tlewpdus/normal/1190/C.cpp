#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3f;

int n, k;
char str[100100];
int arr[100100];
int pmaxi[2][100100];
int smini[2][100100];
int smaxi[2][100100];
int pmini[2][100100];

void print(int t) {
    if (t==1) puts("quailty");
    if (t==0) puts("tokitsukaze");
    if (t==-1) puts("once again");
    exit(0);
}

int main() {
    scanf("%d%d",&n,&k);
    scanf("%s",str);
    for (int i=0;i<n;i++) arr[i]=str[i]-'0';
    for (int i=0;i<2;i++) {
        int s, e;
        for (s=0;s<n;s++) if (arr[s]==i) break;
        for (e=n-1;e>=0;e--) if (arr[e]==i) break;
        if (e-s+1<=k) print(0);
    }
    for (int i=0;i<2;i++) {
        for (int j=0;j<n;j++) {
            pmini[i][j] = min((j?pmini[i][j-1]:n),arr[j]==i?j:n);
            pmaxi[i][j] = max((j?pmaxi[i][j-1]:-1),arr[j]==i?j:-1);
        }
        for (int j=n-1;j>=0;j--) {
            smaxi[i][j] = max((j!=n-1?smaxi[i][j+1]:-1),arr[j]==i?j:-1);
            smini[i][j] = min((j!=n-1?smini[i][j+1]:n),arr[j]==i?j:n);
        }
    }
    int ff = 0;
    for (int i=0;i<=n-k;i++) {
        for (int j=0;j<2;j++) {
            int fl = 1;
            for (int l=0;l<2;l++) {
                int s = min({j==l?i:n,i?pmini[l][i-1]:n,i<n-k?smini[l][i+k]:n});
                int e = max({j==l?i+k-1:-1,i?pmaxi[l][i-1]:-1,i<n-k?smaxi[l][i+k]:-1});
                if (e-s+1<=k) fl = 0;
            }
            if (fl) ff=1;
        }
    }
    print(ff?-1:1);

    return 0;
}