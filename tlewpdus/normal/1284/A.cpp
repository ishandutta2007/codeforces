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

char str[30][20];
char ttr[30][20];
int n, m;

int main() {
    scanf("%d%d",&n,&m);
    for (int i=0;i<n;i++) scanf(" %s",str[i]);
    for (int i=0;i<m;i++) scanf(" %s",ttr[i]);
    int q;
    scanf("%d",&q);
    for (int i=0;i<q;i++){
        int a;
        scanf("%d",&a); a--;
        printf("%s%s\n",str[a%n],ttr[a%m]);
    }

	return 0;
}