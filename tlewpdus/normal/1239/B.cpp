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

int n, mini;
int mcnt, ans, ta=1, tb=1;
char str[300100];
int sum[600100];

void solve(int s, int e) {
    int cnt1 = 0;
    for (int i=s;i<e;i++) {
        if (sum[i]==mini+1) cnt1++;
    }
    if (ans<cnt1) {
        ta=s;tb=e;
        ans=cnt1;
    }
    int cnt2 = 0, p=s, tcnt = 0;
    for (int i=s+1;i<e;i++) {
        if (sum[i]==mini+1) {
            if (ans<tcnt+mcnt) {
                ans=tcnt+mcnt;
                ta=p+1;
                tb=i;
            }
            p=i;
            tcnt=0;
        }
        if (sum[i]==mini+2) tcnt++;
    }
}

int main() {
    scanf("%d",&n);
    scanf("%s",str+1);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+(str[i]=='('?1:-1);
    if (sum[n]) {
        puts("0");
        puts("1 1");
        return 0;
    }
    for (int i=1;i<=n;i++) mini = min(mini,sum[i]);
    for (int i=n+1;i<=2*n;i++) sum[i]=sum[i-n];
    for (int i=1;i<=n;i++) {
        if (sum[i]==mini)mcnt++;
    }
    if (ans<mcnt) {
        ans=mcnt;
    }
    int ploc = -1;
    for (int i=1;i<=n*2;i++) {
        if (sum[i]==mini) {
            if (~ploc) {
                solve(ploc+1,i);
            }
            ploc = i;
        }
    }
    printf("%d\n",ans);
    printf("%d %d\n",(ta>n?ta-n:ta),(tb>n?tb-n:tb));

	return 0;
}