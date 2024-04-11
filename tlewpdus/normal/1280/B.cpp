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

int n, m;
char str[100][100];

int main() {
    int t;

    scanf("%d",&t);
    while(t--) {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) scanf("%s",str[i]);
        int aa = 1, ap = 1;
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++) {
                if (str[i][j]=='P') aa = 0;
                else ap = 0;
            }
        }
        if (aa) {puts("0"); continue;}
        if (ap) {puts("MORTAL"); continue;}
        int flag = 1;
        for (int j=0;j<m;j++) if (str[0][j]=='P') flag = 0;
        if (flag) {puts("1"); continue;}
        flag = 1;
        for (int j=0;j<m;j++) if (str[n-1][j]=='P') flag = 0;
        if (flag) {puts("1"); continue;}
        flag = 1;
        for (int j=0;j<n;j++) if (str[j][0]=='P') flag = 0;
        if (flag) {puts("1"); continue;}
        flag = 1;
        for (int j=0;j<n;j++) if (str[j][m-1]=='P') flag = 0;
        if (flag) {puts("1"); continue;}
        if (str[0][0]=='A'||str[0][m-1]=='A'||str[n-1][0]=='A'||str[n-1][m-1]=='A') {
            puts("2"); continue;
        }
        int done = 0;
        for (int i=0;i<n;i++) {
            int flag = 1;
            for (int j=0;j<m;j++) if (str[i][j]=='P') flag = 0;
            if (flag) {puts("2"); done=1; break;}
        }
        if (done) continue;
        for (int j=0;j<m;j++) {
            int flag = 1;
            for (int i=0;i<n;i++) if (str[i][j]=='P') flag = 0;
            if (flag) {puts("2"); done=1; break;}
        }
        if (done) continue;
        flag = 0;
        for (int j=0;j<m;j++) if (str[0][j]=='A') flag = 1;
        for (int j=0;j<m;j++) if (str[n-1][j]=='A') flag = 1;
        for (int j=0;j<n;j++) if (str[j][0]=='A') flag = 1;
        for (int j=0;j<n;j++) if (str[j][m-1]=='A') flag = 1;
        if (flag) {puts("3"); continue;}
        puts("4");
    }

	return 0;
}