#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f;

int n;
char str[1010];
int ans[1010];

int main() {
    int i;

    scanf("%s",str);
    n = strlen(str);
    for (i=0;i<n;i++) {
        if ((i!=n-1&&str[i]!=str[i+1])||(i==n-1&&str[i]=='a')) {
            ans[i]=1;
        }
    }
    for (i=0;i<n;i++) printf("%d ",ans[i]);
    printf("\n");

    return 0;
}